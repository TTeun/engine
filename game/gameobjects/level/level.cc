#include "level.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

Level::Level(SDL_Renderer *screen_renderer, char const * path)
  : SpriteBox(screen_renderer, path), m_tiles(new vector<TILE_TYPE>)
{
  cout << "Level constructor\n";
}

Level::~Level(){
  cout << "Level destructor\n";
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
                                 line[i] == 'g' ? TILE_TYPE::TOP   :
                                                  TILE_TYPE::EMPTY ;

        --index;
      }
    }
  } else {
    cout << "Cannot read level file!\n";
  }
}
