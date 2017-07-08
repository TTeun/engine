#ifndef __TRANSFORM__H
#define __TRANSFORM__H

#include <iostream>

class Transform{
public:

  static void set_size(size_t _w, size_t _h);
  static int to_screen_x(int _x);
  static int to_screen_y(int _y);

private:
  static size_t w; // declared in transform.cc
  static size_t h;



};


#endif
