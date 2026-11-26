export module piece;

import <compare>;
import <set>;
import <map>;
export import ids;

export enum class PieceType { Data, Virus };

export enum class Direction { Up, Down, Left, Right };

export class Move {
public:
  int dy;
  int dx;
  auto operator<=>(const Move &) const = default;
  Move(Direction dir);
  Move(int dy, int dx);
};

export class Piece {

public:
  PieceId id;
  PlayerId owner;
  PieceType type;
  int strength;
  std::set<Move> moveset;
  std::map<PlayerId, bool> visibility;
  bool isVisibleTo(PlayerId player);
  void revealTo(PlayerId player);
};
