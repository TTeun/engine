#include "transform.h"

size_t Transform::w; // defined in game.cc
size_t Transform::h;

void Transform::set_size(size_t _w, size_t _h){
  w = _w;
  h = _h;
}

int Transform::to_screen_x(int _x){
  return _x;
}

int Transform::to_screen_y(int _y){
  return h - _y;
}
