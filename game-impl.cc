module game;

// player ids are 1-indexed
Player &Game::player(PlayerId id) { return players.at(id.value - 1); }

bool Game::handleBattle(Piece &opponent, Piece &challenger) {
  opponent.revealTo(challenger.owner);
  challenger.revealTo(opponent.owner);

  if (opponent.strength > challenger.strength) {
    // Opponent wins
    board.download(challenger.id, player(opponent.owner));
    return false;
  } else {
    // You win (you're stronger or tie)
    board.download(opponent.id, player(challenger.owner));
    return true;
  }
}

bool Game::move(PieceId pieceId, Direction dir) {
  auto optionalpos = board.findPiece(pieceId);

  if (!optionalpos.has_value())
    return false;

  auto pos = optionalpos.value();
  auto &piece = board.getPiece(pieceId);

  if (piece.owner != currentPlayer)
    return false;

  Move step{dir};
  auto next = Position{pos.row + step.dy, pos.col + step.dx};

  if (!board.inBoundsLeftRight(next))
    return false;

  bool offTop = next.row < 0;
  bool offBottom = next.row >= Board::height;
  if (offTop || offBottom) {
    bool opponentsEdge = piece.owner == PlayerId{1} ? offBottom : offTop;
    if (!opponentsEdge)
      return false;
    board.download(piece.id, player(piece.owner));
    endTurn();
    return true;
  }

  auto &nextsquare = board.at(next);

  if (nextsquare.effect && nextsquare.effect->blocking(piece))
    return false;

  // Both pieces of the same player
  if (nextsquare.occupant.has_value() &&
      board.getPiece(nextsquare.occupant.value()).owner == piece.owner)
    return false;

  enter(piece, next);
  endTurn();
  return true;
}

void Game::enter(Piece &piece, Position next) {
  auto &nextsquare = board.at(next);

  // squareEffect is called
  if (nextsquare.effect) {
    if (auto enterResult = nextsquare.effect->onEnter(piece);
        enterResult.has_value()) {
      board.download(piece.id, player(enterResult.value()));
      return; // Nothing can happen after if something is downloaded
    }
  }

  if (nextsquare.occupant.has_value()) {
    auto &opponent = board.getPiece(nextsquare.occupant.value());
    // Battle
    if (!handleBattle(opponent, piece))
      return;
  }

  board.relocate(piece.id, next);
}

void Game::endTurn() {
  checkWin();
  currentPlayer = currentPlayer == PlayerId{1} ? PlayerId{2} : PlayerId{1};
  abilityUsedThisTurn = false;
  notifyObservers();
}

void Game::checkWin() {
  for (auto player : players) {
    if (player.downloadedData == 4) {
      win(player);
    }
    if (player.downloadedData == 4) {
      player.defeated = true;
    }
  }
  auto pred = [](const Player &p) { return !p.defeated; };

  auto it = std::ranges::find_if(players, pred);

  if (it != players.end() && std::ranges::find_if(std::next(it), players.end(),
                                                  pred) == players.end()) {
    auto &player = *it;
    win(player);
  }
}
