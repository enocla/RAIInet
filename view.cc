export module view;

import observer;
import game;

export class View : public Observer {
  protected:
    Game &game;
    int viewpoint;
  public:
    void notify() override;
    virtual void render() = 0;
};
