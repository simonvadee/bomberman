//
// BombNbBonus.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Mon Jun  8 14:53:30 2015 Aurélien GIRARDEAU
// Last update Tue Jun  9 14:20:09 2015 Aurélien GIRARDEAU
//

#ifndef BOMBNB_BONUS_HH
# define BOMBNB_BONUS_HH

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

class						BombNbBonus : public AObj
{
private :
  float						_posX;
  float						_posY;
  gdl::Texture					_texture;
  gdl::Geometry					_geometry;
  std::map<std::pair<float, float>, e_obj>*	_dynamicMap;
public :
  BombNbBonus(float, float, std::map<std::pair<float, float>, e_obj>*);
  virtual	~BombNbBonus();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const&, gdl::Input&);
  virtual void	draw(gdl::AShader&, gdl::Clock const&);
};

#endif /* BOMBNB_BONUS_HH */