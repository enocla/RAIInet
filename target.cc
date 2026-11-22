export module target;

import <variant>;
import piece;

export class Position {
public:
  int row;
  int col;
};

export class Target {
public:
  std::variant<PieceId, Position> value;
};
