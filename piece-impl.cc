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
