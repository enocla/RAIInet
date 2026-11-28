export module textdisplay;

import <optional>;
import ids;
import game;
import view;

export class TextDisplay : public View {
  private:
    void printPlayer(PlayerId player, PlayerId viewer) const;
    void printBoard() const;
  public:
    explicit TextDisplay(Game &game, std::optional<PlayerId> viewpoint = std::nullopt);
    void render() override;
};
