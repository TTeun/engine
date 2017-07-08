#ifndef __SDL_DELETER__H
#define __SDL_DELETER__H

#include <SDL2/SDL.h>

// These destructors allow wrapping SDL objects in unique_ptrs.

struct sdl_deleter
{
  void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
  void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
  void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
};

#endif
