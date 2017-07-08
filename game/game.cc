#include "game.h"
#include "display/spritebox/spritebox.h"

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
  SpriteBox *sprite_box = new SpriteBox(window->screen_renderer(), "assets/player/player.png");
  SDL_Rect des_rect{100,100, 64, 64};

  while (not input->has_quit())
  {

    window->clear();
    sprite_box->render(&des_rect);
    window->render();

    input->poll_input();
  }

  delete sprite_box;

}
