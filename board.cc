export module board;

import <vector>;
import piece;
import player;
import square;
export import target;

export class Board {
public:
  const int width = 8;
  const int height = 8;
  Board();

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
