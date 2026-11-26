export module command;

import piece;
export import target;

export enum class CommandType {
  Move,
  Ability,
  Board,
  Abilities,
  Sequence,
  Quit
};

export class Command {
public:
  CommandType type;
  PieceId piece;
  Direction direction;
  int abilityId;
  Target target;
};
