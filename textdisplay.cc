export module textdisplay;

import <optional>;
import ids;
import game;
import view;

export class TextDisplay : public View {
  public:
    explicit TextDisplay(Game &game, std::optional<PlayerId> viewpoint = std::nullopt);
    void render() override;
};
