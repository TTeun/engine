#ifndef __COLOR__H
#define __COLOR__H

class Color {
public:
  Color(float _r, float _g, float _b);
  ~Color() = default;

private:
  float m_r;
  float m_g;
  float m_b;

public:
  float r();
  float g();
  float b();

  int int_r();
  int int_g();
  int int_b();
};

inline float Color::r(){
  return m_r;
}

inline float Color::g(){
  return m_g;
}

inline float Color::b(){
  return m_b;
}

inline int Color::int_r(){
  return static_cast<int>(255 * m_r);
}

inline int Color::int_g(){
  return static_cast<int>(255 * m_g);
}

inline int Color::int_b(){
  return static_cast<int>(255 * m_b);
}

#endif
