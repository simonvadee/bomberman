//
// SpeedBonus.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Mon Jun  8 14:55:39 2015 Aurélien GIRARDEAU
// Last update Tue Jun  9 15:59:06 2015 Aurélien GIRARDEAU
//

#include "SpeedBonus.hh"

SpeedBonus::SpeedBonus(float posX,
		       float posY,
		       std::map<std::pair<float, float>, e_obj>* dMap)
  : AObj(B_SPEEDBONUS),
    _posX(posX),
    _posY(posY),
    _dynamicMap(dMap)
{
  (*_dynamicMap)[std::make_pair<float, float>(_posX, _posY)] = B_SPEEDBONUS;
}

SpeedBonus::~SpeedBonus()
{
  (*_dynamicMap)[std::make_pair<float, float>(_posX, _posY)] = EMPTY;
}

bool		SpeedBonus::initialize()
{
  if (_texture.load("./libgdl/assets/speed.tga") == false)
    throw BombermanError::TextureLoadFailure("Cannot load the speed texture\n");
  _geometry.pushVertex(glm::vec3(0.3, -0.3, 0.3));
  _geometry.pushVertex(glm::vec3(0.3, 0.3, 0.3));
  _geometry.pushVertex(glm::vec3(-0.3, 0.3, 0.3));
  _geometry.pushVertex(glm::vec3(-0.3, -0.3, 0.3));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(0.3, -0.3, -0.3));
  _geometry.pushVertex(glm::vec3(0.3, 0.3, -0.3));
  _geometry.pushVertex(glm::vec3(-0.3, 0.3, -0.3));
  _geometry.pushVertex(glm::vec3(-0.3, -0.3, -0.3));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(0.3, -0.3, -0.3));
  _geometry.pushVertex(glm::vec3(0.3, 0.3, -0.3));
  _geometry.pushVertex(glm::vec3(0.3, 0.3, 0.3));
  _geometry.pushVertex(glm::vec3(0.3, -0.3, 0.3));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(-0.3, -0.3, 0.3));
  _geometry.pushVertex(glm::vec3(-0.3, 0.3, 0.3));
  _geometry.pushVertex(glm::vec3(-0.3, 0.3, -0.3));
  _geometry.pushVertex(glm::vec3(-0.3, -0.3, -0.3));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(0.3, 0.3, 0.3));
  _geometry.pushVertex(glm::vec3(0.3, 0.3, -0.3));
  _geometry.pushVertex(glm::vec3(-0.3, 0.3, -0.3));
  _geometry.pushVertex(glm::vec3(-0.3, 0.3, 0.3));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(0.3, -0.3, -0.3));
  _geometry.pushVertex(glm::vec3(0.3, -0.3, 0.3));
  _geometry.pushVertex(glm::vec3(-0.3, -0.3, 0.3));
  _geometry.pushVertex(glm::vec3(-0.3, -0.3, -0.3));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  translate(glm::vec3(0, 0, 1) * _posY);
  translate(glm::vec3(1, 0, 0) * _posX);
  return (true);
}

void		SpeedBonus::update(gdl::Clock const&, gdl::Input&)
{
}

void		SpeedBonus::draw(gdl::AShader& shader, gdl::Clock const&)
{
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
