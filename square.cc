export module square;

import <optional>;
import <memory>;
import squareeffect;
import piece;

export enum class Terrain { Regular, Server, Blockade };

export class Square {
public:
  std::optional<PieceId> occupant;
  Terrain terrain = Terrain::Regular;
  std::optional<int> owner;
  std::unique_ptr<SquareEffect> effect;
};
