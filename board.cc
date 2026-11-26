export module board;

import <vector>;
import <optional>;
import piece;
import player;
import square;
export import target;

export class Board {

  void addServers();

public:
  static const int width = 8;
  static const int height = 8;
  Board(std::vector<Piece> link1, std::vector<Piece> link2);

  // GO TO ROW AND THEN COLUMN
  // i.e. vertical and then horizontal
  std::vector<std::vector<Square>> squares;
  std::vector<Piece> pieces;

  bool inBoundsLeftRight(Position &position) const;
  Square &at(Position position);
  std::optional<Position> findPiece(PieceId pieceId) const;
  Piece &getPiece(PieceId pieceId);

  // only way to download a link
  void download(PieceId pieceId, Player &recipient);
  void relocate(PieceId pieceId, Position to);

private:
  // TODO: make this more elegant
  // rows are 0-indexed, p1 starts at the top
  const int starting_heights_p1[width] = {0, 0, 0, 1, 1, 0, 0, 0};
  const int starting_heights_p2[width] = {7, 7, 7, 6, 6, 7, 7, 7};
};
