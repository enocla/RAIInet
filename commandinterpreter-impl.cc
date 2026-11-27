module commandinterpreter;
import <fstream>;
import <stdexcept>;

CommandInterpreter::CommandInterpreter(Game &game) : game{game} {}

void CommandInterpreter::run(std::istream &in) {
  for (std::string line; !quit && !game.isOver() && std::getline(in, line);) {
    try {
      Command command = parse(line);
      if (command.type == CommandType::Quit) {
        quit = true;
      } else if (command.type == CommandType::Sequence) {
        std::ifstream file{command.filename};
        if (!file)
          throw std::invalid_argument{"can't open " + command.filename};
        run(file);
      } else {
        game.handleCommand(command);
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
    }
  }
}
