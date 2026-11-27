export module game;

import <vector>;
import <memory>;
import <optional>;
import observer;
import player;
import piece;
import board;
import ability;
import command;

export struct GameSetup {
  std::vector<Piece> links1, links2;
  std::vector<std::unique_ptr<Ability>> abilities1, abilities2;
};

export class Game : public Subject {
public:
  Game(GameSetup setup);

  std::vector<Player> players;
  Board board;
  PlayerId currentPlayer{1};
  bool abilityUsedThisTurn = false;
  std::optional<PlayerId> winner;
  std::vector<std::unique_ptr<Ability>> abilities;

  Player &player(PlayerId); // look up an existing player by id, ids start at 1

  // 1. check that it can move there (off the edge, if so, download for mover)
  // 2. check that it can move there with blocking()
  // 3. run SquareEffect::onEnter
  // 4. Handle battle
  // returns true if the move was legal and applied, then the turn then ends
  // if not a legal move, returns false, changing nothing, e.g.:
  //  - if the link isn't the current player's
  //  - is already downloaded
  //  - would leave the map, etc
  bool move(PieceId pieceId, Direction dir);

  // The int is the card's slot number in abilities
  // returns true if the card was played (was valid)
  bool useAbility(int, Target);

  void handleCommand(Command);

  // should be called after every ability and move
  void checkWin();

  bool isOver() const;

private:
  bool handleBattle(Piece &opponent, Piece &challenger);
  void enter(Piece &piece, Position next);
  void endTurn();
};
