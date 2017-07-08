#ifndef __GAME__H
#define __GAME__H

#include "display/window/window.h"
#include "input/input.h"

#include <memory>
#include <SDL2/SDL.h>

class Game {
public:
  Game();
  ~Game();

  void run(char const * path);
  bool init_game();

private:
  std::unique_ptr<Window> window = nullptr;
  std::unique_ptr<Input> input = nullptr;

  bool running = true;
};

#endif
