#include "rigidbody.h"

#include <iostream>

using namespace std;

RigidBody::RigidBody(int _x, int _y, int _w, int _h, size_t _weight)
  : SDL_Rect{_x, _y, _w, _h}, weight(_weight)
{
  cout << "RigidBody constructor\n";
}

RigidBody::RigidBody()
{
  cout << "RigidBody constructor\n";
}

RigidBody::~RigidBody(){
  cout << "RigidBody destructor\n";
}
