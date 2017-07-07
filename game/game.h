#ifndef __GAME__H
#define __GAME__H

#include "display/window/window.h"
#include <memory>

class Game {
public:
  Game();
  ~Game();

  void run();

private:
  std::unique_ptr<Window> window = nullptr;

};




#endif
