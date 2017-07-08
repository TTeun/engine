#ifndef __TRANSFORM__H
#define __TRANSFORM__H

#include <iostream>

class Transform{
public:

  static void set_screen_size(size_t _w, size_t _h);
  static void set_level_size(size_t _w, size_t _h);

  static int to_screen_x(int _x);
  static int to_screen_y(int _y);

  static int level_w();
  static int level_h();

private:
  static size_t m_screen_w; // declared in transform.cc
  static size_t m_screen_h;

  static size_t m_level_w; // declared in transform.cc
  static size_t m_level_h;



};


#endif
