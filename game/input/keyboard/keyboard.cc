#include "keyboard.h"

Keyboard::Keyboard()
  : state(SDL_GetKeyboardState(NULL))
{
}

Keyboard::~Keyboard(){
  state = nullptr;
}

bool Keyboard::is_pressed(SDL_Scancode code){
  return state[code];
}

bool Keyboard::up_pressed(){
  return (is_pressed(SDL_SCANCODE_W) || is_pressed(SDL_SCANCODE_UP));
}

bool Keyboard::down_pressed(){
  return (is_pressed(SDL_SCANCODE_S) || is_pressed(SDL_SCANCODE_DOWN));
}

bool Keyboard::left_pressed(){
  return (is_pressed(SDL_SCANCODE_A) || is_pressed(SDL_SCANCODE_LEFT));
}

bool Keyboard::right_pressed(){
  return (is_pressed(SDL_SCANCODE_D) || is_pressed(SDL_SCANCODE_RIGHT));
}
