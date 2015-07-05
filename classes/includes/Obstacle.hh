/*
** vadee_s
*/

#ifndef OBSTACLE_H_
# define OBSTACLE_H_

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

class Obstacle : public AObj
{
private :
  float		_posX;
  float		_posY;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;


public :
  Obstacle(float posX, float posY);
  virtual ~Obstacle();

  virtual bool	initialize();
  virtual void	update ( gdl :: Clock const &clock, gdl :: Input &input);
  virtual void	draw(gdl::AShader &shader,gdl::Clock const& clock);
};

#endif /* !OBSTACLE_H_ */
