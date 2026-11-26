module board;
import <memory>;
import serverport;

void Board::addServers() {
  // top two
  at(Position{1, 4}).effect = std::make_unique<ServerPort>(PlayerId{1});
  at(Position{1, 5}).effect = std::make_unique<ServerPort>(PlayerId{1});

  // bottom two server ports
  at(Position{height, 4}).effect = std::make_unique<ServerPort>(PlayerId{2});
  at(Position{height, 5}).effect = std::make_unique<ServerPort>(PlayerId{2});
}

Board::Board(std::vector<Piece> link1, std::vector<Piece> link2) {
  squares.reserve(height);
  for (int i = 0; i < height; ++i) {
    auto &row = squares.emplace_back();
    row.reserve(width);
    for (int j = 0; j < width; ++j) {
      row.emplace_back();
    }
  }

  pieces.reserve(width * 2);

  addServers();

  for (int i = 0; i < link1.size(); i++) {
    at(Position{starting_heights_p1[i], i}).occupant = link1.at(i).id;
    pieces.push_back(std::move(link1.at(i)));
  }

  for (int i = 0; i < link2.size(); i++) {
    at(Position{starting_heights_p2[i], i}).occupant = link2.at(i).id;
    pieces.push_back(std::move(link1.at(i)));
  }
}

Square &Board::at(Position position) {
  return squares.at(position.row).at(position.col);
}

std::optional<Position> Board::findPiece(PieceId pieceId) const {
  for (int row = 0; row < squares.size(); row++) {
    for (int col = 0; col < squares.at(row).size(); col++) {
      auto &cell = squares.at(row).at(col);
      if (cell.occupant.has_value() && cell.occupant.value() == pieceId) {
        return Position{row, col};
      }
    }
  }
  return std::nullopt;
}

Piece &Board::getPiece(PieceId pieceId) {
  for (auto &piece : pieces) {
    if (piece.id == pieceId) {
      return piece;
    }
  }
  throw "Invalid piece id";
}

void Board::download(PieceId pieceId, Player &recipient) {
  auto pos = findPiece(pieceId);
  if (pos.has_value()) {
    auto piece = getPiece(pieceId);

    at(pos.value()).occupant.reset();
    piece.revealTo(recipient.id);

    if (piece.type == PieceType::Data) {
      recipient.downloadedData++;
    } else {
      recipient.downloadedViruses++;
    }
  } else {
    throw "Invalid piece to download";
  }
}
