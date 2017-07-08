#include "transform.h"

size_t Transform::m_screen_w; // defined in game.cc
size_t Transform::m_screen_h;
size_t Transform::m_level_w; // defined in game.cc
size_t Transform::m_level_h;

void Transform::set_screen_size(size_t _w, size_t _h){
  m_screen_w = _w;
  m_screen_h = _h;
}

void Transform::set_level_size(size_t _w, size_t _h){
  m_level_w = _w;
  m_level_h = _h;
}

int Transform::to_screen_x(int _x){
  return _x;
}

int Transform::to_screen_y(int _y){
  return m_screen_h - _y;
}

int Transform::level_w(){
  return m_level_w;
}

int Transform::level_h(){
  return m_level_h;
}
