export module square;

import <optional>;
import piece;

export enum class Terrain { Regular, Server, Firewall, Blockade };

export class Square {
public:
  std::optional<PieceId> occupant;
  Terrain terrain = Terrain::Regular;
  std::optional<int> owner;
};
