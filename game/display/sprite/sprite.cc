#include "sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

SDL_Renderer *Sprite::m_screen_renderer; // Inited in Game::init_game()

Sprite::Sprite(char const * path)
{
  cout << "Sprite constructor\n";

  SDL_Surface *surface = load_surface(path);
  load_texture(surface);
  SDL_FreeSurface( surface );
}

Sprite::~Sprite(){
  cout << "Sprite destructor\n";
}

SDL_Surface *Sprite::load_surface(char const * path){
  SDL_Surface *temp_surface;
  temp_surface = IMG_Load( path );

  if( temp_surface == NULL )
  {
    cout << "Unable to load image %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success  = false;
  }

  return temp_surface;
}

void Sprite::load_texture(SDL_Surface *surface){
  m_texture = unique_ptr<SDL_Texture, sdl_deleter>(
              SDL_CreateTextureFromSurface( m_screen_renderer, surface ),
              sdl_deleter()
            );

  if (not m_texture.get()){
    cout << "Unable to convert to texture %s! SDL Error: " <<  SDL_GetError() << '\n';
    m_success = false;
  }
  SDL_QueryTexture(m_texture.get(), NULL, NULL, &dest_rec.w, &dest_rec.h);

}


SDL_Texture *Sprite::texture(){
  return m_texture.get();
}

bool Sprite::is_success(){
  return m_success;
}

void Sprite::set_renderer(SDL_Renderer *m_renderer){
  m_screen_renderer = m_renderer;
}
