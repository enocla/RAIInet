export module piece;

import <set>;
import <map>;

export enum class PieceType { Data, Virus };

export class PieceId {
public:
  int value;
};

export class Move {
public:
  int dx;
  int dy;
};

export class Piece {
public:
  PieceId id;
  int owner;
  PieceType type;
  int strength;
  std::set<Move> moveset;
  std::map<int, bool> visibility;
  bool isVisibleTo(int player);
  void revealTo(int player);
};
