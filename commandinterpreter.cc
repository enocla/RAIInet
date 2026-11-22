export module commandinterpreter;

import <string>;
import command;

export class CommandInterpreter {
  public:
    void run();
    Command parse(std::string);
};
