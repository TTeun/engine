#ifndef __RIGIDBODY__H
#define __RIGIDBODY__H

#include <SDL2/SDL.h>

class RigidBody : public SDL_Rect {
public:
  RigidBody();
  RigidBody(int _x, int _y, int _w, int _h, size_t _weight);
  ~RigidBody();

protected:
  size_t weight;
  int vx = 0;
  int vy = 0;
};

#endif
