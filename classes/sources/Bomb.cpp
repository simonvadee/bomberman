//
// Bomb.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue Jun  2 21:50:12 2015 Aurélien GIRARDEAU
// Last update Fri Jun 12 16:32:40 2015 Aurélien GIRARDEAU
//

#include "Bomb.hh"

Bomb::Bomb(float posX,
	   float posY,
	   std::vector<AObj*>* objects,
	   std::map<std::pair<float, float>, e_obj>* dMap,
	   int bombLvl)
  : AObj(BOMB),
    _posX(posX),
    _posY(posY),
    _countDown(0.0f),
    _objects(objects),
    _dynamicMap(dMap),
    _bombLvl(bombLvl)
{
  (*_dynamicMap)[std::make_pair<float, float>(_posX, _posY)] = BOMB;
}

Bomb::~Bomb()
{
}

bool		Bomb::initialize()
{
  setScale(glm::vec3(0.002f, 0.002f, 0.002f));
  _model = AssetsManager::getBombModel();
  translate(glm::vec3(_posX, 0.0f, _posY));
  return(true);
}

void		Bomb::update(gdl::Clock const& clock, gdl::Input&)
{
  _countDown += clock.getElapsed();
  if (_countDown >= 3.0f)
    explode();
}

void		Bomb::draw(gdl::AShader &shader, gdl::Clock const& clock)
{
  _model->draw(shader, getTransformation(), clock.getElapsed());
}

void				Bomb::findWallToDestroy(float const posX, float const posY)
{
  std::vector<AObj*>::iterator	it;
  glm::vec3			pos;

  for (it = _objects->begin(); it != _objects->end(); ++it)
    {
      if ((pos = (*it)->getPosition()).x == posX && pos.z == posY)
	{
	  delete (*it);
	  _objects->erase(it);
	  (*_dynamicMap)[std::make_pair<float, float>(posX, posY)] = EMPTY;
	  break ;
	}
    }
}

void				Bomb::findBombToDestroy(float const posX, float const posY)
{
  std::vector<AObj*>::iterator	it;
  glm::vec3 pos;

  for (it = _objects->begin(); it != _objects->end(); ++it)
    {
      if ((pos = (*it)->getPosition()).x == posX && pos.z == posY)
	{
	  reinterpret_cast<Bomb*>(*it)->explode();
	  break ;
	}
    }
}

bool				Bomb::processExplosion(float const x, float const y)
{
  e_obj				what;

  if ((what = (*_dynamicMap)[std::make_pair<float, float>(x, y)]) != EMPTY
      && what != OBSTACLE
      && what != BOMB
      && what < B_BOMBLVLBONUS)
    return true;
  AObj* explosion = new Explosion(x, y, _objects, _dynamicMap);
  explosion->initialize();
  _objects->push_back(explosion);
  if (what == OBSTACLE || what >= B_BOMBLVLBONUS)
    {
      findWallToDestroy(x, y);
      if (what == OBSTACLE)
	return true;
    }
  if (what == BOMB)
    {
      findBombToDestroy(x, y);
      return true;
    }
  return false;
}

void				Bomb::setExplosions()
{
  float				x;
  float				y;

  for (x = _posX; x >= _posX - static_cast<float>(_bombLvl + 1); x -= 1.0f)
    if (processExplosion(x, _posY))
      break;
  for (x = _posX + 1; x <= _posX + static_cast<float>(_bombLvl + 1); x += 1.0f)
    if (processExplosion(x, _posY))
      break;
  for (y = _posY - 1; y >= _posY - static_cast<float>(_bombLvl + 1); y -= 1.0f)
    if (processExplosion(_posX, y))
      break;
  for (y = _posY + 1; y <= _posY + static_cast<float>(_bombLvl + 1); y += 1.0f)
    if (processExplosion(_posX, y))
      break;
}

void				Bomb::explode()
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
  setExplosions();
  delete this;
}
