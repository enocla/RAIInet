export module commandinterpreter;

import <iostream>;
import <string>;
import command;
import game;

export class CommandInterpreter {
  Game &game;
  bool quit = false;

public:
  explicit CommandInterpreter(Game &game);

  // reads commands until quit, end of input, or the game ending
  void run(std::istream &in);

  Command parse(std::string);
};
