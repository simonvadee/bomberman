//
// limit.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue May 19 16:16:47 2015 Aurélien GIRARDEAU
// Last update Wed Jun 10 12:35:07 2015 Aurélien GIRARDEAU
//

#include "Limit.hh"

Limit::Limit(float sizeX, float sizeY)
  : AObj(LIMIT), _sizeX(sizeX), _sizeY(sizeY)
{
}

Limit::~Limit()
{
}

bool		Limit::initialize()
{
  if (_texture.load("./libgdl/assets/limit.tga") == false)
    throw BombermanError::TextureLoadFailure("Cannot load the limit texture\n");
  // UP
  for (float i = 0.0f; i < _sizeX; i += 1.0f)
    {
      _geometry.pushVertex(glm::vec3(-1.5f + i, 0.5f, -1.5f));
      _geometry.pushVertex(glm::vec3(1.5f + i, 0.5f, -1.5f));
      _geometry.pushVertex(glm::vec3(1.5f + i, 0.5f, -0.5f));
      _geometry.pushVertex(glm::vec3(-1.5f + i, 0.5f, -0.5f));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(-1.5f + i, 0.5f, -1.5f));
      _geometry.pushVertex(glm::vec3(1.5f + i, 0.5f, -1.5f));
      _geometry.pushVertex(glm::vec3(1.5f + i, -0.5f, -1.5f));
      _geometry.pushVertex(glm::vec3(-1.5f + i, -0.5f, -1.5f));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(-1.5f + i, 0.5f, -0.5f));
      _geometry.pushVertex(glm::vec3(1.5f + i, 0.5f, -0.5f));
      _geometry.pushVertex(glm::vec3(1.5f + i, -0.5f, -0.5f));
      _geometry.pushVertex(glm::vec3(-1.5f + i, -0.5f, -0.5f));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    }

  // BOTTOM

  for (float i = 0.0f; i < _sizeX; ++i)
    {
      _geometry.pushVertex(glm::vec3(-1.5f + i, 0.5f, (_sizeY - 1.0f) + 1.5f));
      _geometry.pushVertex(glm::vec3(i + 1.5f, 0.5f, (_sizeY - 1.0f) + 1.5f));
      _geometry.pushVertex(glm::vec3(i + 1.5f, 0.5f, (_sizeY - 1.0f) + 0.5f));
      _geometry.pushVertex(glm::vec3(i -1.5f, 0.5f, (_sizeY - 1.0f) + 0.5f));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(i - 1.5f, 0.5f, (_sizeY - 1.0f) + 1.5f));
      _geometry.pushVertex(glm::vec3(i + 1.5f, 0.5f, (_sizeY - 1.0f) + 1.5f));
      _geometry.pushVertex(glm::vec3(i + 1.5f, -0.5f, (_sizeY - 1.0f) + 1.5f));
      _geometry.pushVertex(glm::vec3(i - 1.5f, -0.5f, (_sizeY - 1.0f) + 1.5f));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
 
      _geometry.pushVertex(glm::vec3(i - 1.5f, 0.5f, (_sizeY - 1.0f) + 0.5f));
      _geometry.pushVertex(glm::vec3(i + 1.5f, 0.5f, (_sizeY - 1.0f) + 0.5f));
      _geometry.pushVertex(glm::vec3(i + 1.5f, -0.5f, (_sizeY - 1.0f) + 0.5f));
      _geometry.pushVertex(glm::vec3(i - 1.5f, -0.5f, (_sizeY - 1.0f) + 0.5f));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    }

  // BORDERS LEFT
  for (float j = 0.0f; j < _sizeY; ++j)
    {
      _geometry.pushVertex(glm::vec3(-1.5f, -0.5f, -1.5f + j));
      _geometry.pushVertex(glm::vec3(-1.5f, 0.5f, -1.5f + j));
      _geometry.pushVertex(glm::vec3(-1.5f, 0.5f, 1.5f + j));
      _geometry.pushVertex(glm::vec3(-1.5f, -0.5f, 1.5f + j));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(-0.5f, -0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3(-0.5f, 0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3(-0.5f, 0.5f, 0.5f + j));
      _geometry.pushVertex(glm::vec3(-0.5f, -0.5f, 0.5f + j));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(-1.5f, 0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3(-0.5f, 0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3(-0.5f, 0.5f, 0.5f + j));
      _geometry.pushVertex(glm::vec3(-1.5f, 0.5f, 0.5f + j));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    }

  // BORDERS RIGHT
  for (float j = 0.0f; j < _sizeY; ++j)
    {
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 1.5f, -0.5f, -1.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 1.5f, 0.5f, -1.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 1.5f, 0.5f, 1.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 1.5f, -0.5f, 1.5f + j));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 0.5f, -0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 0.5f, 0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 0.5f, 0.5f, 0.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 0.5f, -0.5f, 0.5f + j));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 1.5f, 0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 0.5f, 0.5f, -0.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 0.5f, 0.5f, 0.5f + j));
      _geometry.pushVertex(glm::vec3((_sizeX - 1) + 1.5f, 0.5f, 0.5f + j));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    }

  _geometry.build();
  return (true);
}

void		Limit::update(gdl::Clock const&, gdl::Input&)
{
}

void		Limit::draw(gdl::AShader& shader, gdl::Clock const&)
{
  _texture.bind();
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
