import <iostream>;
import <stdexcept>;
import <utility>;
import game;
import gamestarter;
import textdisplay;
import commandinterpreter;

int main(int argc, char *argv[]) {
  try {
    StartOptions options = parseArgs(argc, argv);

    Game game{std::move(options.game)};
    TextDisplay text{game};
    game.attach(&text);

    CommandInterpreter interpreter{game};
    interpreter.run(std::cin);

    if (game.winner)
      std::cout << "Player " << game.winner->value << " wins!\n";
  } catch (std::invalid_argument &e) {
    std::cerr << "error: " << e.what() << '\n';
    return 1;
  } catch (std::exception &e) {
    std::cerr << "internal error: " << e.what() << '\n';
    return 1;
  }
}
