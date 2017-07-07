#ifndef __KEYBOARD__H
#define __KEYBOARD__H

#include <SDL2/SDL.h>

class Keyboard {
public:
  Keyboard();
  bool is_pressed(SDL_Scancode);

private:
  Uint8 const *state;

};


#endif
