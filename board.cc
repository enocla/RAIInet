export module board;

import <vector>;
import piece;
import player;
import square;
export import target;

export class Board {
  int width = 8;
  int height = 8;
public:
  // Square squares[height][width];

  std::vector<std::vector<Square>> squares;

  std::vector<Piece> pieces;
  Square &at(Position position);
  Position findPiece(PieceId pieceId) const;
  Piece &getPiece(PieceId pieceId);

  // only way to download a link
  void download(PieceId pieceId, Player &recipient);
};
