#include <iostream>
#include <memory>
#include "game/game.h"

using namespace std;

int main(){
  unique_ptr<Game> game(new Game());
  // game->run();
  // game

}
