#include "box.h"

Box::Box(Point &_bl, int _w, int _h)
  : SDL_Rect{_bl.x(), _bl.y(), _w, _h}
{}

Box::Box(int _x, int _y, int _w, int _h)
  : SDL_Rect{_x, _y, _w, _h}
{}
