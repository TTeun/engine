#ifndef __POINT__H
#define __POINT__H

class Point {
public:
  Point(int _x, int _y);
  ~Point() = default;

private:
  int m_x;
  int m_y;

public:
  int &x();
  int &y();

};

inline int &Point::x(){
  return m_x;
}

inline int &Point::y(){
  return m_y;
}

#endif
