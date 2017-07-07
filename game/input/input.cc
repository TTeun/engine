#include "input.h"
#include <iostream>

using namespace std;

Input::Input()
  : Keyboard()
{
  cout << "Input constructor\n";
}

Input::~Input(){
  cout << "Input destructor\n";
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
