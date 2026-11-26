export module blockade;

import <optional>;
import piece;
import squareeffect;

export class Blockade : public SquareEffect {
public:
  bool blocking(const Piece &entering) const override; // returns true
  std::optional<PlayerId> onEnter(Piece &entering) override; // does nothing, shouldn't ever get called
  DisplayEffectInfo getDisplayInfo() const override;
};
