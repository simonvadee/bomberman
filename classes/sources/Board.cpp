//
// board.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue May 19 16:16:47 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:57:46 2015 Aurélien GIRARDEAU
//

#include "Board.hh"

Board::Board(float sizeX, float sizeY)
  : AObj(BOARD), _sizeX(sizeX), _sizeY(sizeY)
{
}

Board::~Board()
{
}

bool		Board::initialize()
{
  if (_texture.load("./libgdl/assets/board.tga") == false)
    throw BombermanError::TextureLoadFailure("Cannot load the board texture\n");
  for (float j = 0; j < _sizeY; ++j)
    {
      for (float i = 0; i < _sizeX; ++i)
  	{
	  _geometry.pushVertex(glm::vec3(-0.5 + i, -0.5, -0.5 + j));
	  _geometry.pushVertex(glm::vec3(0.5 + i, -0.5, -0.5 + j));
	  _geometry.pushVertex(glm::vec3(0.5 + i, -0.5, 0.5 + j));
	  _geometry.pushVertex(glm::vec3(-0.5 + i, -0.5, 0.5 + j));
	  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
	  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
	  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
	  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    	}
    }
  _geometry.build();
  return (true);
}

void		Board::update(gdl::Clock const&, gdl::Input&)
{
}

void		Board::draw(gdl::AShader& shader, gdl::Clock const&)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
