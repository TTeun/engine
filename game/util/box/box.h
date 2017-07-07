#ifndef __BOX__H
#define __BOX__H

#include "../point/point.h"

class Box {
public:
  Box(Point &_bl, int _w, int _h);
  ~Box() = default;

private:
  Point m_bl;
  int m_w;
  int m_h;

public:
  Point bl();
  Point br();
  Point tl();
  Point tr();

  int w();
  int h();

  void set_bl(Point &_bl);
  void set_w(int _w);
  void set_h(int _h);
};

//////////// INLINES ////////////

inline Point Box::bl(){
  return m_bl;
}

inline int Box::w(){
  return m_w;
}

inline int Box::h(){
  return m_h;
}

inline void Box::set_bl(Point &_bl){
  m_bl = _bl;
}

inline void Box::set_w(int _w){
  m_w = _w;
}

inline void Box::set_h(int _h){
  m_h = _h;
}

#endif
