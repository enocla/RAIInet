module board;
import <memory>;
import serverport;

void addServers(Board &board) {
  // top two
  board.at(Position{1, 4}).effect = std::make_unique<ServerPort>(PlayerId{1});
  board.at(Position{1, 5}).effect = std::make_unique<ServerPort>(PlayerId{1});

  // bottom two server ports
  board.at(Position{board.height, 4}).effect =
      std::make_unique<ServerPort>(PlayerId{2});
  board.at(Position{board.height, 5}).effect =
      std::make_unique<ServerPort>(PlayerId{2});
}

Board::Board() {
  std::vector<std::vector<Square>> rows;
  rows.reserve(height);
  for (int i = 0; i < height; i++) {
    std::vector<Square> row;
    row.reserve(width);
    for (int j = 0; j < width; j++) {
      row.emplace_back();
    }
  }
}

Square &Board::at(Position position) {
  return squares.at(position.row).at(position.col);
}

std::optional<Position> Board::findPiece(PieceId pieceId) const {
  for (int row = 0; row < squares.size(); row++) {
    for (int col = 0; col < squares.at(row).size(); col++) {
      auto &cell = squares.at(row).at(col);
      if (cell.occupant.has_value() && cell.occupant.value() == pieceId) {
        return Position{row, col};
      }
    }
  }
  return std::nullopt;
}

Piece &Board::getPiece(PieceId pieceId) {
  for (auto &piece : pieces) {
    if (piece.id == pieceId) {
      return piece;
    }
  }
  throw "Invalid piece id";
}

void Board::download(PieceId pieceId, Player &recipient) {
  auto pos = findPiece(pieceId);
  if (pos.has_value()) {
    auto piece = getPiece(pieceId);

    at(pos.value()).occupant.reset();
    piece.revealTo(recipient.id);

    if (piece.type == PieceType::Data) {
      recipient.downloadedData++;
    } else {
      recipient.downloadedViruses++;
    }
  } else {
    throw "Invalid piece to download";
  }
}
