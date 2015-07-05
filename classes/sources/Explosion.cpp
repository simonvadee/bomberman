//
// Explosion.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Wed Jun  3 18:39:12 2015 Aurélien GIRARDEAU
// Last update Sat Jun  6 12:29:35 2015 Aurélien GIRARDEAU
//

#include "Explosion.hh"

Explosion::Explosion(float posX,
		     float posY,
		     std::vector<AObj*>* objects,
		     std::map<std::pair<float, float>, e_obj>* dMap)
  : AObj(FIRE), 
    _posX(posX),
    _posY(posY),
    _objects(objects),
    _dynamicMap(dMap),
    _explosionDuration(1.0f)
{
  (*_dynamicMap)[std::make_pair<float, float>(_posX, _posY)] = FIRE;
}

Explosion::~Explosion()
{
}

bool		Explosion::initialize()
{
  _model = AssetsManager::getFireModel();
  translate(glm::vec3(_posX, -0.5f, _posY - 0.5f));
  return(true);
}

void		Explosion::update(gdl::Clock const& clock, gdl::Input&)
{
  _explosionDuration -= clock.getElapsed();
  if (_explosionDuration <= 0.0f)
    endExplosion();
}

void		Explosion::draw(gdl::AShader &shader, gdl::Clock const& clock)
{
  _model->draw(shader, getTransformation(), clock.getElapsed());
}

void				Explosion::endExplosion()
{
  std::vector<AObj*>::iterator	it;

  for (it = _objects->begin(); it != _objects->end(); ++it)
    {
      if (*it == this)
	{
	  _objects->erase(it);
	  break ;
	}
    }
  (*_dynamicMap)[std::make_pair<float, float>(_posX, _posY)] = EMPTY;
  delete this;
}
