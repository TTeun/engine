#include "game.h"
#include "display/sprite/sprite.h"


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
  Sprite *sprite = new Sprite("assets/player/player.png");
  if (not sprite->is_success())
    cout << "Sprite not loaded\n";


  SDL_Rect src_rect;
  SDL_Rect des_rect;

  src_rect.x = 0;
  src_rect.y = 0;
  src_rect.w = 64;
  src_rect.h = 64;


  des_rect.x = 100;
  des_rect.y = 100;
  des_rect.w = 64;
  des_rect.h = 64;

  while (not input->has_quit())
  {

    window->clear();
    SDL_RenderCopy(window->screen_renderer(), sprite->texture(), &src_rect, &des_rect);
    window->render();


    input->poll_input();
  }

  delete sprite;

}
