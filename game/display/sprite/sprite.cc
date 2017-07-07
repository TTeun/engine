#include "sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

SDL_Renderer *Sprite::m_screen_renderer; // Inited in Game::init_game()

Sprite::Sprite(char const * path)
{
  cout << "Sprite constructor\n";

  SDL_Surface *temp_surface;
  temp_surface = IMG_Load( path );
  if( temp_surface == NULL ){
    cout << "Unable to load image %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success  = false;
  }

  m_texture = SDL_CreateTextureFromSurface( m_screen_renderer, temp_surface );
  if (not m_texture){
    cout << "Unable to convert to texture %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success = false;
  }

  SDL_FreeSurface( temp_surface );
  SDL_QueryTexture(m_texture, NULL, NULL, &dest_rec.w, &dest_rec.h);
}

Sprite::~Sprite(){
  cout << "Sprite destructor\n";
  SDL_DestroyTexture( m_texture );
}

SDL_Texture *Sprite::texture(){
  return m_texture;
}

bool Sprite::is_success(){
  return m_success;
}

void Sprite::set_renderer(SDL_Renderer *m_renderer){
  m_screen_renderer = m_renderer;
}
