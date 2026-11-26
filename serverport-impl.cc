module serverport;

ServerPort::ServerPort(PlayerId owner) : owner{owner} {}

bool ServerPort::blocking(const Piece &entering) const {
  if (entering.owner == owner) {
    return true;
  }
  return false;
}

std::optional<PlayerId> ServerPort::onEnter(Piece &entering) { return owner; }

DisplayEffectInfo ServerPort::getDisplayInfo() const {
  return DisplayEffectInfo{DisplayEffectKind::ServerPort, owner};
}
