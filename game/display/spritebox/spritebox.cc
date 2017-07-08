#include "spritebox.h"
#include <iostream>

using namespace std;

SpriteBox::SpriteBox(SDL_Renderer *screen_renderer, char const * path)
  : m_src_rects(new vector<unique_ptr<SDL_Rect>>), m_sprite(new Sprite(path)), m_screen_renderer(screen_renderer)
{
  cout << "SpriteBox constructor\n";
}

SpriteBox::~SpriteBox(){
  cout << "SpriteBox destructor\n";
}

void SpriteBox::render_sprite(SDL_Rect *des_rect){
  SDL_RenderCopy(m_screen_renderer, m_sprite->texture(), m_src_rects->at(m_src_rect_index).get(), des_rect);
}
