export module view;

import observer;
import ids;
import game;

export class View : public Observer {
  protected:
    Game &game;
    PlayerId viewpoint;
  public:
    void notify() override;
    virtual void render() = 0;
};
