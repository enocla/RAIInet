module piece;

Move::Move(int dy, int dx) : dy{dy}, dx{dx} {}

Move::Move(Direction dir) : dy{0}, dx{0} {
  if (dir == Direction::Up) {
    dy = -1;
  } else if (dir == Direction::Down) {
    dy = 1;
  } else if (dir == Direction::Left) {
    dx = -1;
  } else if (dir == Direction::Right) {
    dx = 1;
  }
}

Piece::Piece(PieceId id, PlayerId owner, PieceType type, int strength) : id{id}, owner{owner}, type{type}, strength{strength} {
  moveset.insert(Move{Direction::Up});
  moveset.insert(Move{Direction::Down});
  moveset.insert(Move{Direction::Left});
  moveset.insert(Move{Direction::Right});
}

bool Piece::isVisibleTo(PlayerId player) const {
  // return true if player is owner or has entry in map and false otherwise
  if (player == owner) return true;
  auto it = visibility.find(player);
  if (it == visibility.end()) return false;
  return it->second;
}

void Piece::revealTo(PlayerId player) {
  visibility[player] = true;
}
