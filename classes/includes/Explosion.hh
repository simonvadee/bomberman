//
// Explosion.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Wed Jun  3 18:38:19 2015 Aurélien GIRARDEAU
// Last update Sat Jun  6 12:24:51 2015 Aurélien GIRARDEAU
//

#ifndef EXPLOSION_HH_
# define EXPLOSION_HH_

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
# include "AssetsManager.hh"
# include "AObj.hh"

class						Explosion : public AObj
{
private :
  float						_posX;
  float						_posY;
  gdl::Model*					_model;
  std::vector<AObj*>*				_objects;
  std::map<std::pair<float, float>, e_obj>*	_dynamicMap;
  float						_explosionDuration;
public :
  Explosion(float,
	    float,
	    std::vector<AObj*>*,
	    std::map<std::pair<float, float>, e_obj>*);
  virtual ~Explosion();
  virtual bool	initialize();
  virtual void	update (gdl::Clock const&, gdl::Input&);
  virtual void	draw(gdl::AShader&, gdl::Clock const&);
  void		endExplosion();
};

#endif /* !EXPLOSION_HH_ */
