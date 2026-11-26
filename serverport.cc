export module serverport;

import <optional>;
import piece;
import squareeffect;

// the owner's links cannot enter
// an enemy link entering is downloaded by the owner
export class ServerPort : public SquareEffect {
public:
  PlayerId owner;
  explicit ServerPort(PlayerId owner);
  bool blocking(const Piece &entering) const override;
  std::optional<PlayerId> onEnter(Piece &entering) override;
  DisplayEffectInfo getDisplayInfo() const override;
};
