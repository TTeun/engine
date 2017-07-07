#ifndef __INPUT__H
#define __INPUT__H

#include "keyboard/keyboard.h"

class Input : public Keyboard {
public:
  Input();

  void poll_input();
  bool is_running();

private:
  bool running = true;
  SDL_Event event;

};

#endif
