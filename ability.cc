export module ability;
import <memory>;
import <string>;
import <vector>;

import board;
import player;
import target;

export class Ability {
public:
  PlayerId owner;
  explicit Ability(PlayerId owner);
  virtual ~Ability() = default;
  virtual bool use(Board &, Player &user, const Target &) = 0;
};

export std::unique_ptr<Ability> makeAbility(char letter, PlayerId owner);
export std::vector<std::unique_ptr<Ability>>
makeAbilities(const std::string &order, PlayerId owner);

export class LinkBoost : public Ability {
public:
  explicit LinkBoost(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};

export class FirewallAbility : public Ability {
public:
  explicit FirewallAbility(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};

export class DownloadAbility : public Ability {
public:
  explicit DownloadAbility(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};

export class PolarizeAbility : public Ability {
public:
  explicit PolarizeAbility(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};

export class ScanAbility : public Ability {
public:
  explicit ScanAbility(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};

export class BlockadeAbility : public Ability {
public:
  explicit BlockadeAbility(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};

export class DiagonalAbility : public Ability {
public:
  explicit DiagonalAbility(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};

// this requires two targets we should probably do something else
export class SwapAbility : public Ability {
public:
  explicit SwapAbility(PlayerId owner);
  bool use(Board &, Player &user, const Target &) override;
};
