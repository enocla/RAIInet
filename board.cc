export module board;

import <vector>;
import piece;
import player;
import square;
export import target;

export enum class EntryResult { Blocked, Continue, Downloaded };

export class Board {
public:
  Square squares[8][8];
  std::vector<Piece> pieces;
  Square &at(Position);
  Position findPiece(PieceId) const;
  Piece &getPiece(PieceId);
  void download(PieceId, Player &recipient);

  EntryResult enterTerrain(Position destination, PieceId mover, std::vector<Player> &players);
};
