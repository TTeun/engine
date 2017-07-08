#ifndef __BOX__H
#define __BOX__H

#include "../point/point.h"
#include <SDL2/SDL.h>

class Box : public SDL_Rect{
public:
  Box(Point &_bl, int _w, int _h);
  Box(int _x, int _y, int _w, int _h);
  ~Box() = default;

private:

public:

  int get_x();
  int get_y();
  int get_w();
  int get_h();

  void set_x(int _x);
  void set_y(int _y);
  void set_w(int _w);
  void set_h(int _h);
};

//////////// INLINES ////////////

inline int Box::get_x(){
  return x;
}

inline int Box::get_y(){
  return y;
}

inline int Box::get_w(){
  return w;
}

inline int Box::get_h(){
  return h;
}

inline void Box::set_x(int _x){
  x = _x;
}

inline void Box::set_y(int _y){
  y = _y;
}

inline void Box::set_w(int _w){
  w = _w;
}

inline void Box::set_h(int _h){
  h = _h;
}

#endif
