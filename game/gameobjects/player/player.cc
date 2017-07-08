#include "player.h"
#include "../../display/transform/transform.h"

#include <iostream>
#include <cmath>
using namespace std;

Player::Player(SDL_Renderer *screen_renderer, char const * path)
  : SpriteBox(screen_renderer, path), m_des_rect(new SDL_Rect{0,0,64,64})
{
  cout << "Player constructor\n";
  m_src_rects->clear();
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{0, 0, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{32, 0, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{64, 0, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{0, 32, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{32, 32, 32, 32}));
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{64, 32, 32, 32}));

  // Initialize RigidBody
  x = 100;
  y = 2000;
  w = 64;
  h = 64;
  weight = 80;
}

Player::~Player(){
  cout << "Player destructor\n";
}

void Player::set_input(Input *input){
  m_input = input;
}

void Player::handle_input(){
  if (m_input->right_pressed())
    vx += weight / 20;

  if (m_input->left_pressed())
    vx -= weight / 20;

  if (m_input->up_pressed()){
    vy += weight / 20;
    jump_state = JUMP_STATE::JUMPED;
  }
}

void Player::update(){
  handle_input();

  if (jump_state == JUMP_STATE::JUMPED)
    vy -= 1;

  x += vx;
  x = min(max(0, x), 10 * (Transform::level_w() - w));

  y += vy;

  player_dir = vx > 0  ? PLAYER_DIR::RIGHT  :
               vx < 0  ? PLAYER_DIR::LEFT   :
               vx == 0 ? PLAYER_DIR::CENTER :
                         PLAYER_DIR::CENTER ;

  m_src_rect_index = player_dir == PLAYER_DIR::CENTER  ? 0 :
                     player_dir == PLAYER_DIR::RIGHT   ? 1 :
                     player_dir == PLAYER_DIR::LEFT    ? 2 :
                                                         0 ;

  m_src_rect_index += vy >= 0 ? 0 :
                      vy <  0 ? 3 :
                                0 ;
}

void Player::render(){
  update();
  m_des_rect->x = Transform::to_screen_x(x / 10);
  m_des_rect->y = Transform::to_screen_y(y / 10 + m_des_rect->h);
  render_sprite(m_des_rect.get());
}
