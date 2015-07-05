//
// Camera.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Fri May 22 12:51:11 2015 Aurélien GIRARDEAU
// Last update Fri Jun 12 20:59:10 2015 Aurélien GIRARDEAU
//

#ifndef CAMERA_HH_
# define CAMERA_HH_

# include <OpenGL.hh>
# include <Game.hh>
# include <SdlContext.hh>
# include <BasicShader.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include "Player.hh"

class			Camera
{
private :
  int			_nbPlayers;
  float			_width;
  float			_height;
  float			_nearPlane;
  float			_farPlane;
  glm::vec3		_eye;
  glm::vec3		_target;
  glm::vec3		_up;
  glm::mat4		_projection;
  glm::mat4		_transformation;
  gdl::BasicShader*	_shader;
  Player*		_playerOne;
  Player*		_playerTwo;
  glm::vec3		_zoom;
  bool			_isFinished;
public :
  Camera(int		nbPlayers,
	 float const&	width,
	 float const&	height,
	 float const&	nearPlane = 0.1f,
	 float const&	farPlane = 200.0f);
  ~Camera();
  bool			initialize(gdl::BasicShader*);
  bool			update(gdl::Input&);
  glm::mat4		getTransformation() const;
  glm::mat4		getProjection() const;
  void			setPlayer(const e_obj, Player*);
  void			unsetPlayer(const e_obj);
private :
  Camera(Camera const&);
  Camera&		operator=(Camera const&);
  void			setTarget();
  void			setEye();
};

#endif /* !CAMERA_HH_ */
