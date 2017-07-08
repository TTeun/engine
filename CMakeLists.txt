cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(game)

add_executable(
  game
  main.cc
  game/game.cc
  game/display/window/window.cc
  game/display/sprite/sprite.cc
  game/display/spritebox/spritebox.cc
  game/input/keyboard/keyboard.cc
  game/input/input.cc
  game/util/point/point.cc
  game/util/box/box.cc
  game/util/color/color.cc
  game/gameobjects/player/player.cc
  game/gameobjects/level/level.cc
  game/display/transform/transform.cc
  game/physics/rigidbody/rigidbody.cc
)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
