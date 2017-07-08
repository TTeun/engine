#include "spritebox.h"
#include <iostream>

using namespace std;

SpriteBox::SpriteBox(SDL_Renderer *screen_renderer, char const * path)
  : m_sprite(new Sprite(path)), m_screen_renderer(screen_renderer), m_src_rects(new   vector<   unique_ptr<SDL_Rect>  >)
{
  cout << "SpriteBox constructor\n";
  m_src_rects->clear();
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{0, 0, 32, 32}));
}

SpriteBox::~SpriteBox(){
  cout << "SpriteBox destructor\n";
}

void SpriteBox::render(SDL_Rect *des_rect){
  SDL_RenderCopy(m_screen_renderer, m_sprite->texture(), m_src_rects->at(m_src_rect_index).get(), des_rect);
}
