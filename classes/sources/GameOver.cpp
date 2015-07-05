//
// GameOver.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Jun 13 16:42:20 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 17:37:33 2015 Aurélien GIRARDEAU
//

#include "GameOver.hh"

GameOver::GameOver()
  : AObj(GAMEOVER), _posX(0.0f), _posY(0.0f)
{
}

GameOver::~GameOver()
{
}

bool		GameOver::initialize()
{
  if (_texture.load("./libgdl/assets/game_over.tga") == false)
    throw BombermanError::TextureLoadFailure("Cannot load the GameOver texture\n");
  _geometry.pushVertex(glm::vec3(-12.0f, 0.0f, -7.0f));
  _geometry.pushVertex(glm::vec3(12.0f, 0.0f, -7.0f));
  _geometry.pushVertex(glm::vec3(12.0f, 0.0f, 7.0f));
  _geometry.pushVertex(glm::vec3(-12.0f, 0.0f, 7.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  return true;
}

void		GameOver::update(gdl::Clock const&, gdl::Input&)
{
}

void		GameOver::draw(gdl::AShader& shader, gdl::Clock const&)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
