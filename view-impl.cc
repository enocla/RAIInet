module view;

View::View(Game &game, std::optional<PlayerId> viewpoint) : game{game}, viewpoint{viewpoint} {}

void View::notify() {
    render();
}
