module ability;
import <memory>;
import <algorithm>;
import <stdexcept>;

Ability::Ability(PlayerId owner) : owner{owner} {}

LinkBoost::LinkBoost(PlayerId owner) : Ability{owner} {}
FirewallAbility::FirewallAbility(PlayerId owner) : Ability{owner} {}
DownloadAbility::DownloadAbility(PlayerId owner) : Ability{owner} {}
PolarizeAbility::PolarizeAbility(PlayerId owner) : Ability{owner} {}
ScanAbility::ScanAbility(PlayerId owner) : Ability{owner} {}
BlockadeAbility::BlockadeAbility(PlayerId owner) : Ability{owner} {}
DiagonalAbility::DiagonalAbility(PlayerId owner) : Ability{owner} {}
SwapAbility::SwapAbility(PlayerId owner) : Ability{owner} {}

std::unique_ptr<Ability> makeAbility(char letter, PlayerId owner) {
  switch (letter) {
  case 'L':
    return std::make_unique<LinkBoost>(owner);
  case 'F':
    return std::make_unique<FirewallAbility>(owner);
  case 'D':
    return std::make_unique<DownloadAbility>(owner);
  case 'S':
    return std::make_unique<ScanAbility>(owner);
  case 'P':
    return std::make_unique<PolarizeAbility>(owner);
  case 'B':
    return std::make_unique<BlockadeAbility>(owner);
  case 'A':
    return std::make_unique<DiagonalAbility>(owner);
  case 'E':
    return std::make_unique<SwapAbility>(owner);
  }
  throw std::invalid_argument{std::string{"unknown ability "} + letter};
}

std::vector<std::unique_ptr<Ability>> makeAbilities(const std::string &order,
                                                    PlayerId owner) {
  if (order.size() != 5)
    throw std::invalid_argument{"need exactly 5 abilities"};

  std::vector<std::unique_ptr<Ability>> abilities;
  for (char c : order) {
    if (std::ranges::count(order, c) > 2)
      throw std::invalid_argument{std::string{"at most 2 of "} + c};
    abilities.push_back(makeAbility(c, owner));
  }
  return abilities;
}
