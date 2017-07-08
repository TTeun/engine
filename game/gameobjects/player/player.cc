#include "player.h"

#include <iostream>
using namespace std;

Player::Player(SDL_Renderer *screen_renderer, char const * path)
  : SpriteBox(screen_renderer, path), m_des_box(new Box{100, 100, 64, 64})
{
  cout << "Player constructor\n";
  m_src_rects->clear();
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{0, 0, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{32, 0, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{64, 0, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{0, 32, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{32, 32, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{64, 32, 32, 32}));
}

Player::~Player(){
  cout << "Player destructor\n";
}

void Player::set_input(Input *input){
  m_input = input;
}

void Player::update(){
  if (m_input->up_pressed())
    jump_state = JUMP_STATE::JUMPED;
  else
    jump_state = JUMP_STATE::GROUNDED;



  m_src_rect_index = player_dir == PLAYER_DIR::CENTER  ? 0 :
                     player_dir == PLAYER_DIR::RIGHT   ? 1 :
                     player_dir == PLAYER_DIR::LEFT    ? 2 :
                                                         0 ;

  m_src_rect_index += jump_state == JUMP_STATE::GROUNDED       ? 0 :
                      jump_state == JUMP_STATE::JUMPED         ? 3 :
                      jump_state == JUMP_STATE::DOUBLE_JUMPED  ? 3 :
                                                                 0 ;
}

void Player::render(){
  update();
  render_sprite(static_cast<SDL_Rect*> (m_des_box.get()) );
}
