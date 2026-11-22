export module ability;

import board;
import player;
import target;

export class Ability {
public:
  int Owner;
  virtual ~Ability() = default;
  virtual bool use(Board &, Player &user, const Target &) = 0;
};

export class LinkBoost : public Ability {};

export class FirewallAbility : public Ability {};

export class DownloadAbility : public Ability {};

export class PolarizeAbility : public Ability {};

export class ScanAbility : public Ability {};

export class BlockadeAbility : public Ability {};

export class DiagonalAbility : public Ability {};

export class SwapAbility : public Ability {};
