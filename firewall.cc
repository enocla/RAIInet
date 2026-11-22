export module firewall;

import piece;
import squareeffect;

export class Firewall : public SquareEffect {
public:
  int owner;
  explicit Firewall(int owner);
  int onEnter(Piece &entering) override;
};
