export module firewall;

import <optional>;
import piece;
import squareeffect;

// Firewall is played targeting any empty square on the board other than the
// server ports. When passing through this square, opponent links are revealed
// and, if they are viruses, immediately downloaded by their owner. A square
// with a firewall with it is usually printed to the display with an “m” for a
// firewall by player 1 and a “w” for a firewall by player 2. If a link is
// placed on a firewall, print the link rather than the firewall. Links owned by
// the player who placed firewall are unaffected by this ability. If an opponent
// attempts to battle a player’s link which is stationed on the player’s
// firewall: the firewall effect applies prior to the battle taking place

export class Firewall : public SquareEffect {
public:
  PlayerId owner;
  explicit Firewall(PlayerId owner);
  std::optional<PlayerId> onEnter(Piece &entering) override;
  DisplayEffectInfo getDisplayInfo() const override;
};
