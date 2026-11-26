export module squareeffect;

import <optional>;
import piece;

// This is just for rendering
export enum class DisplayEffectKind { ServerPort, Firewall, Blockade };

export struct DisplayEffectInfo {
  DisplayEffectKind kind;
  std::optional<PlayerId> owner; // if it needs an owner, e.g. firewall
};

export class SquareEffect {
public:
  virtual ~SquareEffect() = default;

  // returns true if this square blocks entry
  // game must call this before anything else happens
  virtual bool blocking(const Piece &entering) const { return false; }

  // returns no value if the move continues (e.g with a battle)
  // playerId: the player who downloads the entering link.
  virtual std::optional<PlayerId> onEnter(Piece &entering) = 0;

  virtual DisplayEffectInfo getDisplayInfo() const = 0;
};
