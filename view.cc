export module view;

import <optional>;
import observer;
import ids;
import game;

export class View : public Observer {
protected:
  Game &game;
  std::optional<PlayerId> viewpoint;

public:
  explicit View(Game &game, std::optional<PlayerId> viewpoint = std::nullopt);
  void notify() override;
  virtual void render() = 0;
};
