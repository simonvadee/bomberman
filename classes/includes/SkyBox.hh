//
// SkyBox.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Fri Jun 12 20:28:05 2015 Aurélien GIRARDEAU
// Last update Fri Jun 12 20:52:16 2015 Aurélien GIRARDEAU
//

#ifndef SKYBOX_HH_
# define SKYBOX_HH_

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
# include <utility>
# include "AObj.hh"

class		SkyBox : public AObj
{
private :
  float		_sizeX;
  float		_sizeY;
  float		_camFarPlane;
  gdl::Geometry	_geometry;
  gdl::Texture	_texture;

public :
  SkyBox(float, std::pair<int, int> const&);
  virtual ~SkyBox();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const& clock, gdl::Input& input);
  virtual void	draw(gdl::AShader& shader, gdl::Clock const& clock);
};

#endif /* !SKYBOX_HH_ */
