#ifndef __PLAYER__H
#define __PLAYER__H

#include "../../display/spritebox/spritebox.h"
#include "../../input/input.h"
#include "../../physics/rigidbody/rigidbody.h"
#include <memory>

class Player : public SpriteBox, public RigidBody {
public:
  Player(SDL_Renderer *screen_renderer, char const * path);
  ~Player();

  void set_input(Input *input);

  void render();
  void update();


private:
  std::unique_ptr<RigidBody> m_rigid_body;
  Input *m_input;

  enum class JUMP_STATE {
    GROUNDED,
    JUMPED,
    DOUBLE_JUMPED
  };
  JUMP_STATE jump_state = JUMP_STATE::GROUNDED;

  enum class PLAYER_DIR {
    CENTER,
    LEFT,
    RIGHT
  };
  PLAYER_DIR player_dir = PLAYER_DIR::RIGHT;
  std::unique_ptr<SDL_Rect> m_des_rect;

  void handle_input();
};


#endif
