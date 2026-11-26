export module piece;

import <compare>;
import <set>;
import <map>;
export import ids;

export enum class PieceType { Data, Virus };

export class Move {
public:
  int dx;
  int dy;
  auto operator<=>(const Move &) const = default; 
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
