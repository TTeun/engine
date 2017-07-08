#include "level.h"
#include "../../display/transform/transform.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

Level::Level(SDL_Renderer *screen_renderer, char const * path)
  : SpriteBox(screen_renderer, path), m_tiles(new vector<TILE_TYPE>)
{
  cout << "Level constructor\n";
  m_des_rect.x = 0;
  m_des_rect.y = 0;
  m_des_rect.w = 32;
  m_des_rect.h = 32;

  m_src_rect_index = 0;
  m_src_rects->clear();
  m_src_rects->push_back(unique_ptr<SDL_Rect>(new SDL_Rect{0, 0, 32, 32}));
}

Level::~Level(){
  cout << "Level destructor\n";
}

void Level::render(){
  size_t h = 0;
  size_t w = 0;
  for (size_t i = 0; i != m_tiles->size(); ++i)
    if ((*m_tiles.get())[i] != TILE_TYPE::EMPTY){
      w = i % m_level_width;
      h = i / m_level_width + 1;
      m_des_rect.x = Transform::to_screen_x(32 * w);
      m_des_rect.y = Transform::to_screen_y(32 * h);
      render_sprite(&m_des_rect);
    }
}

void Level::read_level(char const * path)
{
  cout << "Reading level\n";
  ifstream level_file;
  level_file.open(path);

  string line;
  if (level_file.is_open())
  {
    level_file >> m_level_height;
    level_file >> m_level_width;

    m_tiles.get()->resize(m_level_width * m_level_height);
    size_t index = m_level_width * m_level_height - 1;
    getline(level_file, line);

    int height = m_level_height - 2;

    while (getline(level_file, line))
    {
      --height;
      assert(line.length() == m_level_width);
      for (size_t i = 0; i != m_level_width; ++i)
      {

        (*m_tiles.get())[index] = line[i] == '.' ? TILE_TYPE::EMPTY :
                                  line[i] == 't' ? TILE_TYPE::TOP   :
                                                  TILE_TYPE::EMPTY ;

        --index;
      }
    }
  } else {
    cout << "Cannot read level file!\n";
  }
}
