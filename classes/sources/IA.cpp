//
// IA.cpp for bomber in /home/ngo-va_a/rendu/bomberman/classes
//
// Made by Arthur Ngo Van
// Login   <ngo-va_a@epitech.net>
//
// Started on  Thu May  7 12:49:35 2015 Arthur Ngo Van
// Last update Fri Jun 12 17:44:21 2015 Aurélien GIRARDEAU
//

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>

#include "Bomb.hh"
#include "IA.hh"

IA::IA(std::pair<int, int> const& pos)
  : AObj(BASIC_IA),
    _pos(pos),
    _baseSpeed(0.05f),
    _speed(_baseSpeed),
    _epsilon(_speed * 0.33f),
    _inDanger(false),
    _realPos(std::make_pair(static_cast<float>(_pos.first), static_cast<float>(_pos.second))),
    // _lastPos(std::make_pair(-1f, -1f)),
    _isAnim(false),
    _nextMove(TOP),
    _onBomb(false),
    _bombLvl(0),
    _timeReload(0),
    _maxBombCount(1),
    _bombCount(_maxBombCount)
{
  initALL();
  _weightValue[PLAYER1] = 15;
  _weightValue[PLAYER2] = 15;
  _weightValue[OBSTACLE] = 4;
  _weightValue[BOMB] = -20;
  _weightValue[BASIC_IA] = 15;
}

IA::IA(std::pair<int, int> const& pos, int humanTargetWeight, int iaTargetWeight, int obstacleTargetWeight)
  : AObj(BASIC_IA),
    _pos(pos),
    _baseSpeed(0.05f),
    _speed(_baseSpeed),
    _epsilon(_speed * 0.33f),
    _inDanger(false),
    _realPos(std::make_pair(static_cast<float>(_pos.first), static_cast<float>(_pos.second))),
    // _lastPos(std::make_pair(-1f, -1f)),
    _isAnim(false),
    _nextMove(TOP),
    _onBomb(false),
    _bombLvl(0),
    _timeReload(0),
    _maxBombCount(1),
    _bombCount(_maxBombCount)
{
  initALL();
  _weightValue[PLAYER1] = humanTargetWeight;
  _weightValue[PLAYER2] = humanTargetWeight;
  _weightValue[OBSTACLE] = obstacleTargetWeight;
  _weightValue[BOMB] = -20;
  _weightValue[BASIC_IA] = iaTargetWeight;
}

void			IA::initALL()
{
  srand(time(NULL));

  _position = glm::vec3(_pos.first, -0.5f, _pos.second);

  _weightValue[WALL] = 0;
  _weightValue[B_BOMBLVLBONUS] = 10;
  _weightValue[B_SPEEDBONUS] = 10;
  _weightValue[B_SPEEDMALUS] = 1;
  _weightValue[B_BOMBNBBONUS] = 10;
  _weightValue[FIRE] = -10;

  _frameRate = 0;

  _dir.push_back(std::make_pair(0, -1));
  _dir.push_back(std::make_pair(1, 0));
  _dir.push_back(std::make_pair(0, 1));
  _dir.push_back(std::make_pair(-1, 0));

  _trans[std::make_pair(0, -1)] = TOP;
  _trans[std::make_pair(1, 0)] = RIGHT;
  _trans[std::make_pair(0, 1)] = BOT;
  _trans[std::make_pair(-1, 0)] = LEFT;

  _translate[TOP] = glm::vec3(0, 0, -1);
  _translate[RIGHT] = glm::vec3(1, 0, 0);
  _translate[BOT] = glm::vec3(0, 0, 1);
  _translate[LEFT] = glm::vec3(-1, 0, 0);

  _rotationVector[LEFT] = glm::vec3(0.0f, 270.0f, 0.0f);
  _rotationVector[TOP] = glm::vec3(0.0f, 180.0f, 0.0f);
  _rotationVector[RIGHT] = glm::vec3(0.0f, 90.0f, 0.0f);
  _rotationVector[BOT] = glm::vec3(0.0f, 0.0f, 0.0f);

  _actionBonus[B_BOMBLVLBONUS] = &IA::incrementBombLvl;
  _actionBonus[B_BOMBNBBONUS] = &IA::incrementMaxBombCount;
  _actionBonus[B_SPEEDBONUS] = &IA::incrementSpeed;
  _actionBonus[B_SPEEDMALUS] = &IA::decreaseSpeed;
}

void			IA::setAlive(unsigned int* live)
{
  _alive = live;
}

void			IA::setDynamicMap(std::map<std::pair<float, float>, e_obj>* dMap)
{
  _dynamicMap = dMap;
}

void			IA::setObjectsContainer(std::vector<AObj*>* objects)
{
  _objects = objects;
}

void			IA::setMapSize(int x, int y)
{
  _mapSize = std::make_pair(x, y);
}

bool			IA::isWorthIt(std::pair<int,int>& actual)
{
  e_obj			object = (*_dynamicMap)[std::make_pair<float,float>(static_cast<float>(actual.first), static_cast<float>(actual.second))];

  _ways.front().setWeight(_weightValue[object]);
  if (object != WALL && object != EMPTY)
    {
      if (object == PLAYER1 || object == PLAYER2 || object == OBSTACLE || (object == BOMB && _ways.size() == 1))
	_ways.front().pop();
      _ways.push_back(_ways.front());
      _ways.pop_front();
      if (object != BOMB)
	_validWays += 1;
      return (true);
    }
  return (false);
}

void			IA::findTarget(std::pair<int,int> actual, int depth)
{
  if (depth > 10)
    return (_ways.pop_front());
  if (depth == 0)
    _ways.push_front(Way(actual));
  else
    _ways.front() + actual;
  if (isWorthIt(actual) && depth != 0)
    return;
  for (int i = 0; i < 4; ++i)
    {
      if (_validWays < 100 && goodDir(actual, _dir[(i + _nextMove) % 4]))
	{
	  _ways.push_front(_ways.front());
	  findTarget(std::make_pair(actual.first + _dir[(i + _nextMove) % 4].first, actual.second +
				    _dir[(i + _nextMove) % 4].second), depth + 1);
	}
    }
  _ways.pop_front();
}

bool			IA::wasAlreadyHere(std::pair<int,int> pos)
{
  if (_ways.front().getWay().size() < 1)
    return (false);
  for (std::deque<std::pair<int,int> >::iterator it = _ways.front().getWay().begin(); it != _ways.front().getWay().end(); ++it)
    {
      if ((it->first == pos.first && it->second == pos.second))
	return (true);
    }
  return (false);
}

bool			IA::goodDir(std::pair<int,int>& pos, std::pair<int,int>& add)
{
  e_obj			target;

  if (pos.first + add.first < 0 || pos.first + add.first > _mapSize.first - 1
      || pos.second + add.second < 0 || pos.second + add.second > _mapSize.second - 1)
    return (false);
  target = (*_dynamicMap)[std::make_pair<float,float>(pos.first + add.first, pos.second + add.second)];
  if (target == WALL || wasAlreadyHere(std::make_pair(pos.first + add.first, pos.second + add.second)))
    return (false);
  return (true);
}

bool			IA::bomb()
{
  if (_bombCount > 0 && (_validWays > 1 || !_inDanger))
    {
      AObj*	bomb = new Bomb(glm::round(_position.x),
				glm::round(_position.z),
				_objects,
				_dynamicMap,
				_bombLvl);
      bomb->initialize();
      _objects->push_back(bomb);
      _nextMove = NONE;
      _bombCount -= 1;
      return (true);
    }
  else
    return (false);
}

bool				IA::isPosEqual(std::pair<int, int> dir)
{
  return ((static_cast<float>(dir.first) > _realPos.first - _epsilon && static_cast<float>(dir.second) > _realPos.second - _epsilon) && (static_cast<float>(dir.first) < _realPos.first + _epsilon && static_cast<float>(dir.second) < _realPos.second + _epsilon));
}

bool				IA::isEqual(float real, int dir)
{
  float				epsilon = 0.01;

  return ((static_cast<float>(dir) > real - epsilon && (static_cast<float>(dir) < real + epsilon)));
}

bool				IA::isBetween(std::deque<std::pair<int, int> > main)
{
  main.pop_back();
  if (isPosEqual(main.back()))
    return (true);
  if (_pos.first == main.back().first && isEqual(_realPos.first, _pos.first) && ((_realPos.second >= _pos.second && _realPos.second <= main.back().second) || (_realPos.second <= _pos.second && _realPos.second >= main.back().second)))
    return (true);
      if (_pos.second == main.back().second && isEqual(_realPos.second, _pos.second) && ((_realPos.first >= _pos.first && _realPos.first <= main.back().first) || (_realPos.first <= _pos.first && _realPos.first >= main.back().first)))
    return (true);
  return (false);
}

void				IA::findBestTarget()
{
  float				tmp = 0.0;
  std::deque<Way>::iterator	save;
  float				tmpPos = 0.0;
  std::deque<Way>::iterator	savePos;

  _inDanger = false;
  for (std::deque<Way>::iterator it = _ways.begin(); it != _ways.end(); ++it)
    {
      if (fAbs(tmp) < fAbs(it->getWeight()))
  	{
  	  tmp = it->getWeight();
  	  save = it;
  	}
      if (tmpPos < it->getWeight() && (!_onBomb || (_onBomb && !isStraight(_pos, it->getWay()))))
	{
	  tmpPos = it->getWeight();
	  savePos = it;
	}
    }
  if (tmp <= 0)
    {
      _inDanger = true;
      if (tmpPos > 0 && !isStraight(save->getWay().front(), savePos->getWay()))
	save = savePos;
      else
	{
	  findClearWay();
	  tmp = 0;
	}
    }
  if (save != _ways.end() && tmp != 0)
    {
      if (save->getWay().size() != 1 && isBetween(save->getWay()))
	save->getWay().pop_back();
      if (isPosEqual(save->getWay().back()))
      	{
	  save->getWay().pop_back();
	  roundPositions();
	  _nextMove = NONE;

	  if (save->getWay().size() == 0 && !getBonus() && bomb())
	    return ;
	}
      if (save->getWay().size() != 0)
	_nextMove = getNextMove(save->getWay().back().first, save->getWay().back().second);
    }
}

void					IA::roundPositions()
{
  _realPos.first = glm::round(_realPos.first);
  _realPos.second = glm::round(_realPos.second);
  _pos.first = glm::round(_realPos.first);
  _pos.second = glm::round(_realPos.second);
}

bool					IA::goodMove(e_dir move)
{
  std::pair<int,int>			nextPos = std::make_pair(_pos.first + _translate[move].x, _pos.second + _translate[move].z);

  if ((*_dynamicMap)[nextPos] == EMPTY || ((*_dynamicMap)[nextPos] >= B_BOMBLVLBONUS && (*_dynamicMap)[nextPos] <= B_BOMBNBBONUS))
    {
      return (true);
    }
  return (false);
}

void					IA::findOtherWay()
{
  int					nextMove = rand();

  for (int i = 0; i < 4; ++i)
    {
      if (goodMove((e_dir)((i + nextMove) % 4)))
	{
	  _nextMove = (e_dir)((i + nextMove) % 4);
	  return ;
	}
    }
  _nextMove = NONE;
  return ;
}

void					IA::findClearWay()
{
  if (_nextMove != NONE && isPosEqual(std::make_pair(_pos.first + _translate[_nextMove].x, _pos.second + _translate[_nextMove].z)))
    roundPositions();
  if (isPosEqual(_pos) && (_nextMove == NONE || (!goodMove(_nextMove))))
    findOtherWay();
  else if (_nextMove != NONE && !goodMove(_nextMove))
    {
      if (goodMove((e_dir)((_nextMove + 2) % 4)))
	_nextMove = (e_dir)((_nextMove + 2) % 4);
      else
	_nextMove = NONE;
    }
}

bool					IA::isStraight(std::pair<int,int> &bomb, std::deque<std::pair<int,int> > &target)
{
  if ((*_dynamicMap)[std::make_pair<float,float>(target.back().first, target.back().second)] >= B_BOMBLVLBONUS && (*_dynamicMap)[std::make_pair<float,float>(target.back().first, target.back().second)] <= B_BOMBNBBONUS)
    return (false);
  if (bomb.first == target.front().first)
    {
      int				tmp = bomb.first;

      for (std::deque<std::pair<int,int> >::iterator it = target.begin(); it != target.end(); ++it)
	{
	  if (tmp != it->first)
	    return (false);
	}
      return (true);
    }
  if (bomb.second == target.front().second)
    {
      int				tmp = bomb.second;

      for (std::deque<std::pair<int,int> >::iterator it = target.begin(); it != target.end(); ++it)
	{
	  if (tmp != it->second)
	    return (false);
	}
      return (true);
    }
  return (false);
}

bool				IA::getBonus()
{
  e_obj				object = (*_dynamicMap)[std::make_pair<float,float>(_pos.first, _pos.second)];

  if (object == B_BOMBLVLBONUS || object == B_SPEEDBONUS || object == B_BOMBNBBONUS || object == B_SPEEDMALUS)
    {
      glm::vec3			pos;

      for (std::vector<AObj*>::iterator it = _objects->begin(); it != _objects->end(); ++it)
	{
	  pos = (*it)->getPosition();
	  if (pos.x == _pos.first && pos.z == _pos.second)
	    {
	      (this->*_actionBonus[object])();
	      delete (*it);
	      _objects->erase(it);
	      break ;
	    }
	}
      return (true);
    }
  return (false);
}

void				IA::incrementBombLvl()
{
  _bombLvl += 1;
}

void				IA::incrementMaxBombCount()
{
  _maxBombCount += 1;
}

void				IA::decreaseSpeed()
{
  if (_speed >= 2 * _baseSpeed)
    _speed -= _baseSpeed;
}

void				IA::incrementSpeed()
{
  if (_speed < _baseSpeed)
    _speed += _baseSpeed;
}

e_dir				IA::getNextMove(int x, int y)
{
  int				a = (isEqual(_realPos.first, x) ? 0 : (static_cast<float>(x) - _realPos.first) / fAbs(static_cast<float>(x) - _realPos.first));
  int				b = (isEqual(_realPos.second, y) ? 0 : (static_cast<float>(y) - _realPos.second) / fAbs(static_cast<float>(y) - _realPos.second));

  return _trans[std::make_pair(a, b)];
}

float				IA::fAbs(float nb)
{
  if (nb < 0)
    return (-nb);
  return (nb);
}

void			IA::run()
{
  _validWays = 0;
  _ways.clear();
  findTarget(_pos, 0);
  _onBomb = ((*_dynamicMap)[_pos] == BOMB ? true : false);
  findBestTarget();
}

bool		IA::initialize()
{
  setScale(glm::vec3(0.0015f, 0.002f, 0.0015f));
  if (_model.load("./libgdl/assets/marvin.fbx") == false)
    {
      std::cerr << "Cannot load the model texture" << std::endl;
      return (false);
    }
  if (_model.createSubAnim(0, "move", 35, 53) == false)
    {
      std::cerr << "Cannot create the sub anim" << std::endl;
      return (false);
    }
  if (_model.createSubAnim(0, "end", 80, 120) == false)
    {
      std::cerr << "Cannot create the sub anim" << std::endl;
      return (false);
    }
  if (_model.createSubAnim(0, "static", 0, 0) == false)
    {
      std::cerr << "Cannot create the sub anim" << std::endl;
      return (false);
    }
  _frameDuration = 30;
  return (true);
}

void			IA::die()
{
  for (std::vector<AObj*>::iterator it = _objects->begin(); it != _objects->end(); ++it)
    {
      if (*it == reinterpret_cast<AObj*>(this))
	{
	  _objects->erase(it);
	  break ;
	}
    }
  (*_dynamicMap)[std::make_pair<float,float>(glm::round(_realPos.first), glm::round(_realPos.second))] = EMPTY;
  *_alive -= 1;
  delete this;
}

bool			IA::isDead()
{
  if ((*_dynamicMap)[std::make_pair<float,float>(glm::round(_realPos.first), glm::round(_realPos.second))] == FIRE)
    return (true);
  if (_realPos.first < -1 || _realPos.second < -1 || _realPos.first >= _mapSize.first || _realPos.second >= _mapSize.second)
    return (true);
  return (false);
}

void			IA::update(gdl::Clock const &clock, gdl::Input&)
{
  run();
  _timeReload -= clock.getElapsed();
  if (_timeReload <= 0.0f)
    {
      _bombCount = ((_bombCount < _maxBombCount) ? _maxBombCount : _bombCount);
      _timeReload = 1.5f;
    }
  if (_nextMove != NONE)
    {
      if (!_isAnim && (_isAnim = true))
	_model.setCurrentSubAnim("move", false);
      translate(_translate[_nextMove] * _speed);
      _realPos.first += _dir[_nextMove].first * _speed;
      _realPos.second += _dir[_nextMove].second * _speed;
      setRotate(_rotationVector[_nextMove]);
    }
  if (isDead())
    {
      die();
      return ;
    }
}

void	IA::draw(gdl::AShader &shader,gdl::Clock const& clock)
{
  if (_isAnim)
    _frameRate += 1;
  if (_frameRate == _frameDuration)
    {
      _frameRate = 0;
      _isAnim = false;
    }
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
