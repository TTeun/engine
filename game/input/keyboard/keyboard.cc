#include "keyboard.h"

Keyboard::Keyboard()
  : state(SDL_GetKeyboardState(NULL));
{
}

bool Keyboard::is_pressed(SDL_Scancode){
  return state[SDL_Scancode];
}
