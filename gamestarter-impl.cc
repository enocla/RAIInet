module gamestarter;
import <fstream>;
import <random>;
import <algorithm>;
import <stdexcept>;
import <chrono>;
import ability;

const std::vector<std::string> allLinks = {"D1", "D2", "D3", "D4",
                                           "V1", "V2", "V3", "V4"};

std::vector<Piece> makeLinks(PlayerId owner,
                             const std::vector<std::string> &tokens) {
  auto sorted = tokens;
  std::ranges::sort(sorted);
  if (sorted != allLinks)
    throw std::invalid_argument{"links must be D1-D4 and V1-V4"};

  std::vector<Piece> links;
  for (int i = 0; i < 8; i++) {
    auto type = tokens[i][0] == 'V' ? PieceType::Virus : PieceType::Data;
    links.emplace_back(PieceId{(owner.value - 1) * 8 + i}, owner, type,
                       (int)(tokens[i][1] - '0'));
  }
  return links;
}

std::vector<Piece> readPlacement(const std::string &filename, PlayerId owner) {
  std::ifstream file{filename};
  if (!file)
    throw std::invalid_argument{"can't open " + filename};

  std::vector<std::string> tokens;
  for (std::string t; file >> t;)
    tokens.push_back(t);
  return makeLinks(owner, tokens);
}

std::vector<Piece> randomPlacement(PlayerId owner) {
  auto tokens = allLinks;
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng{seed};
  std::ranges::shuffle(tokens, rng);
  return makeLinks(owner, tokens);
}

StartOptions parseArgs(int argc, char *argv[]) {
  std::string link1, link2, ability1 = "LFDSP", ability2 = "LFDSP";
  StartOptions options;

  for (int i = 1; i < argc; i++) {
    std::string flag = argv[i];
    if (flag == "-graphics") {
      options.graphics = true;
      continue;
    }

    if (i + 1 >= argc)
      throw std::invalid_argument{flag + " was passed without argument"};

    std::string value = argv[++i];
    if (flag == "-link1")
      link1 = value;
    else if (flag == "-link2")
      link2 = value;
    else if (flag == "-ability1")
      ability1 = value;
    else if (flag == "-ability2")
      ability2 = value;
    else
      throw std::invalid_argument{"unknown option " + flag};
  }

  auto &g = options.game;
  g.links1 = link1.empty() ? randomPlacement(PlayerId{1})
                           : readPlacement(link1, PlayerId{1});
  g.links2 = link2.empty() ? randomPlacement(PlayerId{2})
                           : readPlacement(link2, PlayerId{2});
  g.abilities1 = makeAbilities(ability1, PlayerId{1});
  g.abilities2 = makeAbilities(ability2, PlayerId{2});
  return options;
}
