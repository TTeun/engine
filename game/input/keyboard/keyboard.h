#ifndef __KEYBOARD__H
#define __KEYBOARD__H

#include <SDL2/SDL.h>

class Keyboard {
public:
  Keyboard();
  ~Keyboard();

  bool is_pressed(SDL_Scancode);

  bool up_pressed();
  bool down_pressed();
  bool left_pressed();
  bool right_pressed();


private:
  Uint8 const *state;

};


#endif
