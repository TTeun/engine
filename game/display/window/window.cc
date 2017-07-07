#include "window.h"

using namespace std;

Window::Window(string title, size_t width, size_t height)
  : m_width(width), m_height(height)
{
  cout << "Window constructor\n";
  if (not init_window(title))
    cout << "Window could not be initialized\n";

  m_screen_renderer = unique_ptr<SDL_Renderer, sdl_deleter> (
                      SDL_CreateRenderer( m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ),
                      sdl_deleter()
                    );

  SDL_SetRenderDrawColor( m_screen_renderer.get(), 0x000, 0xb0, 0xe0, 0x00 );
}

Window::~Window()
{
  cout << "Window destructor\n";
  SDL_Quit();
}

bool Window::init_window(string title)
{
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    cout << "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << '\n';
    return false;
  }

  else
  {
    m_window = unique_ptr<SDL_Window, sdl_deleter>(
               SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE),
               sdl_deleter()
             );

    if( m_window.get() == NULL ) {
      cout << "Window could not be created! SDL_Error: " <<  SDL_GetError() << '\n';
      return false;
    }
  }
  return true;
}
