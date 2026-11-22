export module squareeffect;

import <optional>;
import piece;

export class SquareEffect {
public:
  virtual ~SquareEffect() = default;

  virtual int onEnter(Piece &entering) = 0;
};
