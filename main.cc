#include <iostream>
#include <memory>
#include "game/game.h"

using namespace std;

int main(){
  unique_ptr<Game> game(new Game());
  game->init_game();
  game->run("assets/levels/level3");

}
