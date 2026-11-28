module textdisplay;

import <iostream>;
import <string>;
import board;
import square;
import piece;
import squareeffect;
import player;

const std::string BOARD_BORDER = "========";
const int LINKS_PER_LINE = 4;

void TextDisplay::printPlayer(PlayerId player, PlayerId viewer) const {
  std::cout << "Player " << player.value << ":\n";
  const Player &p = game.player(player);
  std::cout << "Downloaded: " << p.downloadedData << "D, " << p.downloadedViruses << "V\n";
  std::cout << "Abilities: " << 0 << '\n';  // TODO count # of unused abilities
  // link lines
  for (int i = 0; i < LINKS_PER_PLAYER; ++i) {
    if (i % LINKS_PER_LINE != 0) std::cout << ' ';  // space btw entries except for line start/end
    int linkId = (player.value - 1) * LINKS_PER_PLAYER + i;
    const Piece &piece = game.board.getPiece(PieceId{linkId});
    std::cout << piece.symbol() << ": ";
    if (piece.isVisibleTo(viewer)) {
        std::cout << (piece.type == PieceType::Data ? 'D' : 'V') << piece.strength;
    } else {
        std::cout << '?';
    }
    if (i % LINKS_PER_LINE == LINKS_PER_LINE - 1) std::cout << '\n';  // newline after 4th and 8th link
  }
}

void TextDisplay::printBoard() const {
  std::cout << BOARD_BORDER << '\n';
  // display board
  for (int row = 0; row < game.board.height; ++row) {
    for (int col = 0; col < game.board.width; ++col) {
      // get square, check occupant, check square effect
      const Square &square = game.board.at(Position{row, col});
      if (square.occupant) {
        const Piece &piece = game.board.getPiece(*square.occupant);
        std::cout << piece.symbol();
      } else if (square.effect) {
          DisplayEffectInfo info = square.effect->getDisplayInfo();
          switch (info.kind) {
          case DisplayEffectKind::ServerPort:
            std::cout << 'S';
            break;
          case DisplayEffectKind::Firewall:
            std::cout << (info.owner == PlayerId{1} ? 'm' : 'w');
            break;
          case DisplayEffectKind::Blockade:
            std::cout << '_';  // decided to use underscore fn (can change later)
            break;
          }
      } else {
        std::cout << '.';
      }
    }
    std::cout << '\n';
  }
  std::cout << BOARD_BORDER << '\n';
}

TextDisplay::TextDisplay(Game &game, std::optional<PlayerId> viewpoint) : View{game, viewpoint} {}

void TextDisplay::render() {
  // viewer is current player if viewpoint is empty
  PlayerId viewer = viewpoint ? *viewpoint : game.currentPlayer;
  printPlayer(PlayerId{1}, viewer);
  printBoard();
  printPlayer(PlayerId{2}, viewer);
}
