//
// SkyBox.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri Jun 12 20:28:44 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:30:46 2015 Aurélien GIRARDEAU
//

#include "SkyBox.hh"

SkyBox::SkyBox(float farPlane, std::pair<int, int> const& mapSize)
  : AObj(SKYBOX),
    _sizeX(static_cast<float>(mapSize.first)),
    _sizeY(static_cast<float>(mapSize.second)),
    _camFarPlane(farPlane)
{
}

SkyBox::~SkyBox()
{
}

bool		SkyBox::initialize()
{
  _position = glm::vec3(_sizeX / 2, 0.0f, _sizeY / 2);
  if (_texture.load("./libgdl/assets/sky.tga") == false)
    throw BombermanError::TextureLoadFailure("Cannot load the board texture\n");
  _geometry.pushVertex(glm::vec3(_camFarPlane, -_camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(_camFarPlane, _camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, _camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, -_camFarPlane, _camFarPlane));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(_camFarPlane, -_camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(_camFarPlane, _camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, _camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, -_camFarPlane, -_camFarPlane));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(_camFarPlane, -_camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(_camFarPlane, _camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(_camFarPlane, _camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(_camFarPlane, -_camFarPlane, _camFarPlane));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(-_camFarPlane, -_camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, _camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, _camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, -_camFarPlane, -_camFarPlane));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(_camFarPlane, _camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, _camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, _camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, _camFarPlane, _camFarPlane));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));

  _geometry.pushVertex(glm::vec3(_camFarPlane, -_camFarPlane, -_camFarPlane));
  _geometry.pushVertex(glm::vec3(_camFarPlane, -_camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, -_camFarPlane, _camFarPlane));
  _geometry.pushVertex(glm::vec3(-_camFarPlane, -_camFarPlane, -_camFarPlane));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  return true;
}

void		SkyBox::update(gdl::Clock const&, gdl::Input&)
{
}

void		SkyBox::draw(gdl::AShader& shader, gdl::Clock const&)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
