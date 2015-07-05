//
// AObj.hh for bomberman in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Mon May  4 15:31:12 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:48:42 2015 Aurélien GIRARDEAU
//

#ifndef AOBJ_HH_
# define AOBJ_HH_

# include <SdlContext.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include <BasicShader.hh>
# include "Exceptions.hpp"

typedef	enum
  {
    EMPTY,
    PLAYER1 = 1,
    PLAYER2 = 2,
    WALL,
    OBSTACLE,
    BOMB,
    BASIC_IA,
    BOARD,
    LIMIT,
    FIRE,
    B_BOMBLVLBONUS,
    B_SPEEDBONUS,
    B_SPEEDMALUS,
    B_BOMBNBBONUS,
    SKYBOX,
    GAMEOVER
  }	e_obj;

class		AObj
{
protected :
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  e_obj		_type;

public :
  AObj(e_obj type);
  virtual ~AObj();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const&, gdl::Input&);
  virtual void	draw(gdl::AShader&, gdl::Clock const&) = 0;
  e_obj		getType() const;
  glm::vec3	translate(glm::vec3 const&);
  void		rotate(glm::vec3 const& axis, float angle);
  void		scale(glm::vec3 const&);
  void		setScale(glm::vec3 const& scale);
  glm::mat4	getTransformation();
  void		setRotate(glm::vec3 const& rotate);
  glm::vec3	getPosition() const;
};

#endif /* !AOBJ_HH_ */
