#ifndef __PLAYER__H
#define __PLAYER__H

#include "../../display/spritebox/spritebox.h"
#include "../../input/input.h"
#include "../../util/box/box.h"
#include <memory>

class Player : public SpriteBox {
public:
  Player(SDL_Renderer *screen_renderer, char const * path);
  ~Player();

  void set_input(Input *input);

  void render();
  void update();


private:
  std::unique_ptr<Box> m_des_box;
  Input *m_input;

  enum class JUMP_STATE {
    GROUNDED,
    JUMPED,
    DOUBLE_JUMPED
  };
  JUMP_STATE jump_state = JUMP_STATE::JUMPED;

  enum class PLAYER_DIR {
    CENTER,
    LEFT,
    RIGHT
  };
  PLAYER_DIR player_dir = PLAYER_DIR::RIGHT;

};


#endif
