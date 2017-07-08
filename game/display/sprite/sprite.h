#ifndef __SPRITE__H
#define __SPRITE__H

#include <SDL2/SDL.h>
#include <memory>
#include "../sdl_deleter.h"

class Sprite {
public:
  Sprite(char const * path);
  ~Sprite();

  bool is_success();
  SDL_Texture *texture();

  static void set_renderer(SDL_Renderer *m_renderer);

private:
  std::unique_ptr<SDL_Texture, sdl_deleter> m_texture = nullptr;

  SDL_Surface *load_surface(char const * path);
  void load_texture(SDL_Surface *surface);

  bool m_success = true;
  static SDL_Renderer *m_screen_renderer; // Decl in sprite.cc
};

#endif
