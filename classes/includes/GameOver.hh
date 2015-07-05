//
// GameOver.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Sat Jun 13 16:40:58 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:54:12 2015 Aurélien GIRARDEAU
//

#ifndef GAMEOVER_HH_
# define GAMEOVER_HH_

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

class		GameOver : public AObj
{
private :
  float		_posX;
  float		_posY;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
public :
  GameOver();
  virtual ~GameOver();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const&, gdl::Input&);
  virtual void	draw(gdl::AShader&, gdl::Clock const&);
};

#endif /* !GAMEOVER_HH_ */
