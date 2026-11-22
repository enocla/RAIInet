export module game;

import <vector>;
import <memory>;
import observer;
import player;
import piece;
import board;
import ability;
import command;

export class Game : public Subject {
public:
  std::vector<Player> players;
  Board board;
  int currentPlayer;
  bool abilityUsedThisTurn;
  std::vector<std::unique_ptr<Ability>> abilities;
  bool move(PieceId, Direction);
  bool useAbility(int, Target);
  void handleCommand(Command);
  void checkWin();
};
