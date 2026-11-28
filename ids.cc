export module ids;

import <compare>;

export const int LINKS_PER_PLAYER = 8;

export class PieceId {
public:
  int value; // 0-indexed, player p's links are (p-1)*8 to (p-1)*8+7
  auto operator<=>(const PieceId &) const = default;
};

export class PlayerId {
public:
  int value; // 1-indexed, player 1 is PlayerId{1}
  auto operator<=>(const PlayerId &) const = default;
};
