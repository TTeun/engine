#include "game.h"
#include <iostream>

using namespace std;

Game::Game()
  : window( new Window(1000, 800))
{
  cout << "Game constructor\n";
}

Game::~Game(){
  cout << "Game destructor\n";
}

void Game::run(){
  // while (1){
    window->clear();
    window->render();
  // }
}
