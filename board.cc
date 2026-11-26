export module board;

import <vector>;
import piece;
import player;
import square;
export import target;

export class Board {
  static const int width = 8;
  static const int height = 8;

  // TODO: make this more elegant
  const int starting_heights_p1[width] = {1, 1, 1, 2, 2, 1, 1, 1};
  const int starting_heights_p2[width] = {8, 8, 8, 7, 7, 8, 8, 8};

  void addServers();

public:
  Board(std::vector<Piece> link1, std::vector<Piece> link2);

  // GO TO ROW AND THEN COLUMN
  // i.e. vertical and then horizontal
  std::vector<std::vector<Square>> squares;
  std::vector<Piece> pieces;

  Square &at(Position position);
  std::optional<Position> findPiece(PieceId pieceId) const;
  Piece &getPiece(PieceId pieceId);

  // only way to download a link
  void download(PieceId pieceId, Player &recipient);
};
