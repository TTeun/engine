#ifndef __WINDOW__H
#define __WINDOW__H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <string>
#include "../sdl_deleter.h"

class Window {
public:
 Window(std::string title, size_t width, size_t height);
 ~Window();

 void clear();
 void render();

 SDL_Renderer *screen_renderer();
 SDL_Window *window();

private:
  bool init_window(std::string title);

  size_t m_width;
  size_t m_height;

  std::unique_ptr<SDL_Window, sdl_deleter> m_window = nullptr;
  std::unique_ptr<SDL_Renderer, sdl_deleter> m_screen_renderer = nullptr;
};

inline void Window::clear(){
  SDL_RenderClear( m_screen_renderer.get());
}

inline void Window::render(){
  SDL_RenderPresent( m_screen_renderer.get() );
}

inline SDL_Renderer * Window::screen_renderer(){
  return m_screen_renderer.get();
}

inline SDL_Window * Window::window(){
  return m_window.get();
}

#endif
