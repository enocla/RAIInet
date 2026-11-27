export module gamestarter;

import <string>;
import <vector>;
import piece;
import player;
import game;

export struct StartOptions {
  GameSetup game;
  bool graphics = false;
};

export std::vector<Piece> readPlacement(const std::string &filename,
                                        PlayerId owner);
export std::vector<Piece> randomPlacement(PlayerId owner);
export StartOptions parseArgs(int argc, char *argv[]);
