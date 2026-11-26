export module ids;

import <compare>;

export class PieceId {
public:
  int value;
  auto operator<=>(const PieceId &) const = default;
};

export class PlayerId {
public:
  int value; // 1-indexed, player 1 is PlayerId{1}
  auto operator<=>(const PlayerId &) const = default;
};
