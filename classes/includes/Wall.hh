//
// Wall.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Mon Jun  8 14:59:01 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:43:13 2015 Aurélien GIRARDEAU
//

#ifndef WALL_H_
# define WALL_H_

# include <Game.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include "AObj.hh"

class Wall : public AObj
{
private :
  float		_posX;
  float		_posY;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public :
  Wall(float posX, float posY);
  virtual ~Wall();
  virtual bool	initialize();
  virtual void	update ( gdl :: Clock const &clock, gdl :: Input &input);
  virtual void	draw(gdl::AShader &shader,gdl::Clock const& clock);
};

#endif /* !WALL_H_ */
