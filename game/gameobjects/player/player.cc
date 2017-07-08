#include "player.h"

#include <iostream>
using namespace std;

Player::Player(SDL_Renderer *screen_renderer, char const * path)
  : SpriteBox(screen_renderer, path), m_des_box(new Box{100, 100, 64, 64})
{
  cout << "Player constructor\n";
}

Player::~Player(){
  cout << "Player destructor\n";
}

void Player::render(){
  render_sprite(static_cast<SDL_Rect*> (m_des_box.get()) );
}
