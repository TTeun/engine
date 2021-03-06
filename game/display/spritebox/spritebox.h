#ifndef __SPRITE_BOX__H
#define __SPRITE_BOX__H

#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include "../sprite/sprite.h"

typedef std::unique_ptr<std::vector< std::unique_ptr<SDL_Rect> > > rect_vec;

class SpriteBox {
public:
  SpriteBox(SDL_Renderer *screen_renderer, char const * path);
  ~SpriteBox();

  void render_sprite(SDL_Rect *des_rect);

protected:
  size_t m_src_rect_index = 0;
  rect_vec m_src_rects;

private:
  std::unique_ptr<Sprite> m_sprite;
  SDL_Renderer *m_screen_renderer;

};

#endif
