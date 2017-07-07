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

#endif
