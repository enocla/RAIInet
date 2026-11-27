export module graphics;

import <optional>;
import ids;
import game;
import view;

export class GraphicsDisplay : public View {
  public:
    explicit GraphicsDisplay(Game &game, std::optional<PlayerId> viewpoint = std::nullopt);
    void render() override;
};
