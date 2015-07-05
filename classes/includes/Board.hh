//
// board.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Tue May 19 16:17:31 2015 Aurélien GIRARDEAU
// Last update Fri Jun 12 20:31:10 2015 Aurélien GIRARDEAU
//

#ifndef BOARD_HH_
# define BOARD_HH_

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

class		Board : public AObj
{
private :
  float		_sizeX;
  float		_sizeY;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public :
  Board(float, float);
  virtual ~Board();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const& clock, gdl::Input& input);
  virtual void	draw(gdl::AShader& shader, gdl::Clock const& clock);
};

#endif
