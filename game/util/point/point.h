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
  int x();
  int y();

  void set_x(int _x);
  void set_y(int _y);
};

inline int Point::x(){
  return m_x;
}

inline int Point::y(){
  return m_y;
}

inline void Point::set_x(int _x){
  m_x = _x;
}

inline void Point::set_y(int _y){
  m_y = _y;
}

#endif
