#include <iostream>
#include <string>
#include <memory>
#include "game/game.h"

int main(int argc, char **argv)
try
{
  std::unique_ptr<Game> game(new Game());
  game->init_game();
  game->run("assets/levels/level3");

  return 0;
}
catch (...)
{
  return 1;
}
