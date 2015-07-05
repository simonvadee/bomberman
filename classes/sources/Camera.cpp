//
// Camera.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri May 22 12:51:59 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 17:03:50 2015 Aurélien GIRARDEAU
//

#include "Camera.hh"

Camera::Camera(int nbPlayers,
	       float const& width,
	       float const& height,
	       float const& nearPlane,
	       float const& farPlane)
  : _nbPlayers(nbPlayers),
    _width(width),
    _height(height),
    _nearPlane(nearPlane),
    _farPlane(farPlane),
    _playerOne(NULL),
    _playerTwo(NULL),
    _isFinished(false)
{
}

Camera::~Camera()
{
}

bool		Camera::initialize(gdl::BasicShader* shader)
{
  _zoom = glm::vec3(0.0f, 8.0f, 4.0f);
  setEye();
  setTarget();
  _up = glm::vec3(0.0f, 1.0f, 0.0f);
  _projection = glm::perspective(60.0f, _width / _height, _nearPlane, _farPlane);
  _transformation = glm::lookAt(_eye,
				_target,
				_up);
  _shader = shader;
  return true;
}

bool		Camera::update(gdl::Input&)
{
  if (!_isFinished)
    {
      setTarget();
      setEye();
      _transformation = glm::lookAt(_eye,
				    _target,
				    _up);
      _shader->setUniform("view", getTransformation());
      _shader->setUniform("projection", getProjection());
    }
  return true;
}

void		Camera::setEye()
{
  if (_nbPlayers == 1)
    _eye = (_playerOne == NULL ?
	    _playerTwo->getPosition() + _zoom :
	    _playerOne->getPosition() + _zoom);
  else
    _eye = _target + _zoom;
}

void		Camera::setTarget()
{
  if (_nbPlayers == 1)
    _target = (_playerOne == NULL ? _playerTwo->getPosition() : _playerOne->getPosition());
  else
    {
      glm::vec3	p1 = _playerOne->getPosition();
      glm::vec3	p2 = _playerTwo->getPosition();
      _target.y = p1.y;
      _target.x = ((p1.x + p2.x) / 2);
      _target.z = ((p1.z + p2.z) / 2);
      if (glm::distance(p1, p2) < 8.0f)
	_zoom = glm::vec3(0.0f, 8.0f, 4.0f);
      else
	_zoom = glm::vec3(0.0f, glm::distance(p1, p2), glm::distance(p1, p2) / 2);
    }
}

glm::mat4 const &	Camera::getTransformation() const
{
  return _transformation;
}

glm::mat4 const &	Camera::getProjection() const
{
  return _projection;
}

void		Camera::setPlayer(e_obj const type, Player* player)
{
  if (type == PLAYER1)
    _playerOne = player;
  else
    _playerTwo = player;
}

void		Camera::unsetPlayer(e_obj const type)
{
  if (type == PLAYER1)
    _playerOne = NULL;
  else
    _playerTwo = NULL;
  if ((_nbPlayers -= 1) <= 0)
    _isFinished = true;
}
