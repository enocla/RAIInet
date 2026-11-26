export module ids;

import <compare>;

export class PieceId {
public:
  int value;
  auto operator<=>(const PieceId &) const = default;
};

export class PlayerId {
public:
  int value;
  auto operator<=>(const PlayerId &) const = default;
};
