#ifndef __PLAYER__H
#define __PLAYER__H

#include "../../display/spritebox/spritebox.h"
#include "../../util/box/box.h"
#include <memory>

class Player : public SpriteBox {
public:
  Player(SDL_Renderer *screen_renderer, char const * path);
  ~Player();

  void render();

private:
  std::unique_ptr<Box> m_des_box;

};


#endif
