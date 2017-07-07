#include "input.h"

Input::Input()
  : Keyboard()
{

}

void Input::poll_input(){
    while( SDL_PollEvent( &event ) != 0 )
    {
      switch( event.type ){
        case SDL_QUIT:
          running = false;
          break;
        }
    }
}

bool Input::is_running(){
  return running;
}
