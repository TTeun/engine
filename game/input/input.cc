#include "input.h"

Input::Input()
  : Keyboard()
{

}

Input::~Input(){

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

bool Input::has_quit(){
  return not running;
}
