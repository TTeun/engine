#include "game.h"
#include "gameobjects/player/player.h"
#include "gameobjects/level/level.h"

#include <iostream>

using namespace std;

Game::Game()
  : window( new Window("Game!!", 1000, 800)),
    input( new Input )
{
  cout << "Game constructor\n";
}

Game::~Game(){
  cout << "Game destructor\n";
}

bool Game::init_game(){
  Sprite::set_renderer(window->screen_renderer());

  return true;
}

void Game::run()
{

  Player *player = new Player(window->screen_renderer(), "assets/player/player.png");
  player->set_input(input.get());

  while (not input->has_quit())
  {
    input->poll_input();

    window->clear();
    player->render();
    window->render();


  }

}
