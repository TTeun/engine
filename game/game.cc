#include "game.h"
#include <iostream>

using namespace std;

Game::Game()
  : window( new Window(1000, 800)),
    input( new Input )
{
  cout << "Game constructor\n";
}

Game::~Game(){
  cout << "Game destructor\n";
}

void Game::run(){
  while (input->is_running()){
    window->clear();
    window->render();

    input->poll_input();

  }
}
