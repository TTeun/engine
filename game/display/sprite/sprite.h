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
  SDL_Rect dest_rec;
  std::unique_ptr<SDL_Texture, sdl_deleter> m_texture = nullptr;

  bool m_success = true;
  static SDL_Renderer *m_screen_renderer; // Decl in sprite.cc
};

#endif
