export module square;

import <optional>;
import <memory>;
import squareeffect;
import piece;

export class Square {
public:
  std::optional<PieceId> occupant;
  std::unique_ptr<SquareEffect> effect;  // nullptr for a regular square
};
