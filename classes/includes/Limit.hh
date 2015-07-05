//
// limit.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Tue May 19 16:17:31 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:43:53 2015 Aurélien GIRARDEAU
//

#ifndef LIMIT_HH_
# define LIMIT_HH_

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

class		Limit : public AObj
{
private :
  float		_sizeX;
  float		_sizeY;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public :
  Limit(float, float);
  virtual ~Limit();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const& clock, gdl::Input& input);
  virtual void	draw(gdl::AShader& shader, gdl::Clock const& clock);
};

#endif
