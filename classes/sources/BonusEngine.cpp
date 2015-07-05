//
// BonusEngine.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Jun  6 12:32:30 2015 Aurélien GIRARDEAU
// Last update Wed Jun 10 11:27:21 2015 Aurélien GIRARDEAU
//

#include "BonusEngine.hh"

BonusEngine::BonusEngine(std::map<std::pair<float, float>, e_obj> *map, std::vector<AObj*> *obj, int x, int y)
  : _objects(obj),
    _mapX(x),
    _mapY(y),
    _map(map)
{
  _bonusCount[B_BOMBLVLBONUS] = 0;
  _bonusCount[B_SPEEDBONUS] = 0;
  _bonusCount[B_BOMBNBBONUS] = 0;
  _mapCreate[B_BOMBLVLBONUS] = &BonusEngine::createBombLvlBonus;
  _mapCreate[B_BOMBNBBONUS] = &BonusEngine::createBombNbBonus;
  _mapCreate[B_SPEEDBONUS] = &BonusEngine::createSpeedBonus;
  _mapCreate[B_SPEEDMALUS] = &BonusEngine::createSpeedMalus;
}

BonusEngine::~BonusEngine()
{
}

int		BonusEngine::nbBonuses()
{
  int		ret = 0;

  for (std::map<e_obj, int>::iterator it = _bonusCount.begin(); it != _bonusCount.end(); ++it)
    ret += it->second;
  return ret;
}

void		BonusEngine::resetCounter()
{
  for (std::map<e_obj, int>::iterator it = _bonusCount.begin(); it != _bonusCount.end(); ++it)
    it->second = 0;
}

int		BonusEngine::countBonuses()
{
  int		ret = 0;

  resetCounter();
  for (std::vector<AObj*>::iterator it = _objects->begin(); it != _objects->end(); ++it)
    {
      if ((*it)->getType() >= static_cast<e_obj>(10))
	{
	  ++ret;
	  _bonusCount[(*it)->getType()] += 1;
	}
    }
  return ret;
}

e_obj		BonusEngine::determBonus()
{
  e_obj		ret;
  int		less;

  ret = B_BOMBLVLBONUS;
  less = _bonusCount[B_BOMBLVLBONUS];
  for (std::map<e_obj, int>::iterator it = _bonusCount.begin(); it != _bonusCount.end(); ++it)
    {
      if (it->second < less)
	ret = it->first;
    }
  return ret;
}

void		BonusEngine::addBonus(e_obj bonus)
{
  std::pair<float, float>	pos;
  AObj				*obj;

  if (bonus == EMPTY)
    bonus = determBonus();
  else
    _bonusCount[bonus] += 1;
  while (1)
    {
      pos.first = static_cast<float>(rand() % _mapX);
      pos.second = static_cast<float>(rand() % _mapY);
      if ((*_map)[pos] != EMPTY
	  || pos.first == _mapX - 1.0f || pos.first == 0.0f
	  || pos.second == _mapY - 1.0f || pos.first == 0.0f)
	continue ;
      else
	{
	  obj = (this->*_mapCreate[bonus])(pos);
	  obj->initialize();
	  _objects->push_back(obj);
	  (*_map)[pos] = bonus;
	  break ;
	}
    }
}

bool		BonusEngine::initialize()
{
  e_obj		bonus;

  while (nbBonuses() < ((_mapX * _mapY) / 20))
    {
      bonus = static_cast<e_obj>((rand() % 4) + 10);
      addBonus(bonus);
    }
  return true;
}

void		BonusEngine::update()
{
  while (countBonuses() < ((_mapX * _mapY) / 20))
    addBonus(EMPTY);
}

AObj*						BonusEngine::createBombLvlBonus(std::pair<float, float> const& pos)
{
  return new BombLvlBonus(pos.first, pos.second, _map);
}

AObj*						BonusEngine::createBombNbBonus(std::pair<float, float> const& pos)
{
  return new BombNbBonus(pos.first, pos.second, _map);
}

AObj*						BonusEngine::createSpeedBonus(std::pair<float, float> const& pos)
{
  return new SpeedBonus(pos.first, pos.second, _map);
}

AObj*						BonusEngine::createSpeedMalus(std::pair<float, float> const& pos)
{
  return new SpeedMalus(pos.first, pos.second, _map);
}
