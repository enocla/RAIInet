module game;

// player ids are 1-indexed, players vector is 0-indexed
Player &Game::player(PlayerId id) { return players.at(id.value - 1); }
