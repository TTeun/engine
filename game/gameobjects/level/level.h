#ifndef __LEVEL__H
#define __LEVEL__H

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include "../../display/spritebox/spritebox.h"

class Level : public SpriteBox {
public:
  Level(SDL_Renderer *screen_renderer, char const * path);
  ~Level();

  void read_level(char const * path);
  void render();

  size_t width();
  size_t height();

private:
  enum class TILE_TYPE {
    EMPTY,
    TOP
  };
  size_t m_level_height;
  size_t m_level_width;
  std::unique_ptr<std::vector <TILE_TYPE>> m_tiles;
  SDL_Renderer *m_screen_renderer;
  SDL_Rect m_des_rect;
};

inline size_t Level::width(){
  return 32 * m_level_width;
}

inline size_t Level::height(){
  return 32 * m_level_height;
}

#endif
