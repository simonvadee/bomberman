//
// Bomb.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Jun  2 21:50:20 2015 Aurélien GIRARDEAU
// Last update Fri Jun  5 16:41:53 2015 Aurélien GIRARDEAU
//

#ifndef BOMB_H_
# define BOMB_H_

# include <map>
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
# include "Explosion.hh"

class						Bomb : public AObj
{
private :
  float						_posX;
  float						_posY;
  gdl::Model*					_model;
  float						_countDown;
  std::vector<AObj*>*				_objects;
  std::map<std::pair<float, float>, e_obj>*	_dynamicMap;
  int						_bombLvl;

public :
  Bomb(float,
       float,
       std::vector<AObj*>*,
       std::map<std::pair<float, float>, e_obj>*,
       int);
  virtual ~Bomb();
  virtual bool	initialize();
  virtual void	update (gdl::Clock const&, gdl::Input&);
  virtual void	draw(gdl::AShader&, gdl::Clock const&);
  void		explode();

private :
  bool		processExplosion(const float, const float);
  void		setExplosions();
  void		findWallToDestroy(const float, const float);
  void		findBombToDestroy(const float, const float);
};

#endif /* !BOMB_H_ */
