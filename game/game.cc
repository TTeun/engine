#include "game.h"
#include "gameobjects/player/player.h"
#include "gameobjects/level/level.h"
#include "display/transform/transform.h"

#include <iostream>
#include <memory>

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

  unique_ptr<Player> player(new Player(window->screen_renderer(), "assets/player/player.png"));
  player->set_input(input.get());

  unique_ptr<Level> level(new Level(window->screen_renderer(), "assets/level/tile.png"));
  level->read_level("assets/levels/level3");

  int w, h;
  while (not input->has_quit())
  {
    input->poll_input();

    SDL_GetWindowSize(window->window(), &w, &h);
    Transform::set_size(w, h);

    window->clear();

    level->render();
    player->render();

    window->render();
  }

}
