//
// AObj.cpp for bomberman in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Mon May  4 16:36:43 2015 Aurélien GIRARDEAU
// Last update Wed Jun  3 23:02:23 2015 Aurélien GIRARDEAU
//

#include "AObj.hh"

AObj::AObj(e_obj type)
  : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1), _type(type)
{
}

AObj::~AObj()
{
}

bool		AObj::initialize()
{
  return (true);
}

void		AObj::setScale(glm::vec3 const& scale)
{
  _scale = scale;
}

void		AObj::setRotate(glm::vec3 const& rotate)
{
  _rotation = rotate;
}

void		AObj::update(gdl::Clock const&, gdl::Input&)
{
}

glm::vec3	AObj::translate(glm::vec3 const& vect)
{
  _position += vect;
  return vect;
}

void		AObj::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void		AObj::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4	AObj::getTransformation()
{
  glm::mat4	transform(1);

  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, _scale);

  return (transform);
}

e_obj		AObj::getType() const
{
  return _type;
}

glm::vec3	AObj::getPosition() const
{
  return _position;
}
