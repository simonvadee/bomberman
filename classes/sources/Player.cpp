//
// Player.cpp for Bomberman in /home/oscar/rendu/bomberman/classes/sources
//
// Made by Oscar Morizet
// Login   <oscar@epitech.net>
//
// Started on  Tue May  5 15:31:58 2015 Oscar Morizet
// Last update Sat Jun 13 15:57:08 2015 Aurélien GIRARDEAU
// Last update Tue Jun  9 15:52:07 2015 Aurélien GIRARDEAU
//

#include	"Player.hh"
#include	"Bomb.hh"
#include	"AssetsManager.hh"

Player::Player(e_obj playerNum,
	       float posX,
	       float posY)
  : AObj(playerNum),
    _playerNum(playerNum),
    _playerLevel(0),
    _posX(posX),
    _posY(posY),
    _speed(2.4f),
    _isAnim(false),
    _hasToStop(false),
    _frameRate(0),
    _maxBombCount(1),
    _bombCount(_maxBombCount),
    _bombLvl(0),
    _timeReload(1.5f)
{
  _position = glm::vec3(_posX, -0.5f, _posY);
  this->_directionVector[LEFT] = glm::vec3(-1.0f, 0.0f, 0.0f);
  this->_directionVector[TOP] = glm::vec3(0.0f, 0.0f, -1.0f);
  this->_directionVector[RIGHT] = glm::vec3(1.0f, 0.0f, 0.0f);
  this->_directionVector[BOT] = glm::vec3(0.0f, 0.0f, 1.0f);

  this->_rotationVector[LEFT] = glm::vec3(0.0f, 270.0f, 0.0f);
  this->_rotationVector[TOP] = glm::vec3(0.0f, 180.0f, 0.0f);
  this->_rotationVector[RIGHT] = glm::vec3(0.0f, 90.0f, 0.0f);
  this->_rotationVector[BOT] = glm::vec3(0.0f, 0.0f, 0.0f);

  _actionBonus[B_BOMBLVLBONUS] = &Player::incrementBombLvl;
  _actionBonus[B_BOMBNBBONUS] = &Player::incrementMaxBombCount;
  _actionBonus[B_SPEEDBONUS] = &Player::incrementSpeed;
  _actionBonus[B_SPEEDMALUS] = &Player::decreaseSpeed;
}

void	Player::setAlive(unsigned int* live)
{
  _alive = live;
}

void	Player::setDynamicMap(std::map<std::pair<float, float>, e_obj>* dMap)
{
  _dynamicMap = dMap;
}

void	Player::setObjectsContainer(std::vector<AObj*>* objects)
{
  _objects = objects;
}

void	Player::customizeControls(const int left, const int top,
				  const int right, const int bottom, const int dropbomb)
{
  this->_controls[LEFT] = left;
  this->_controls[TOP] = top;
  this->_controls[RIGHT] = right;
  this->_controls[BOT] = bottom;
  this->_controls[DROPBOMB] = dropbomb;
}

void	Player::initControlsAsPlayerOne()
{
  this->_controls[LEFT] = SDLK_LEFT;
  this->_controls[TOP] = SDLK_UP;
  this->_controls[RIGHT] = SDLK_RIGHT;
  this->_controls[BOT] = SDLK_DOWN;
  this->_controls[DROPBOMB] = SDLK_RCTRL;
}

void	Player::initControlsAsPlayerTwo()
{
  this->_controls[LEFT] = SDLK_q;
  this->_controls[TOP] = SDLK_z;
  this->_controls[RIGHT] = SDLK_d;
  this->_controls[BOT] = SDLK_s;
  this->_controls[DROPBOMB] = SDLK_LSHIFT;
}

bool	Player::initialize()
{
  setScale(glm::vec3(0.0015f, 0.002f, 0.0015f));
  if (_type == PLAYER1)
    _model = AssetsManager::getCharacterOneModel();
  else
    _model = AssetsManager::getCharacterTwoModel();
  if (_model->createSubAnim(0, "move", 35, 53) == false)
    throw BombermanError::SubAnimFailure("Cannot create the sub animation\n");
  if (_model->createSubAnim(0, "end", 80, 120) == false)
    throw BombermanError::SubAnimFailure("Cannot create the sub animation\n");
  if (_model->createSubAnim(0, "static", 0, 0) == false)
    throw BombermanError::SubAnimFailure("Cannot create the sub animation\n");
  _frameDuration = 30;
  if (this->_playerNum == PLAYER1)
    this->initControlsAsPlayerOne();
  else if (this->_playerNum == PLAYER2)
    this->initControlsAsPlayerTwo();
  return (true);
}

void				Player::update(gdl::Clock const& clock,
					       gdl::Input& input)
{
  _timeReload -= clock.getElapsed();
  if (_timeReload <= 0.0f)
    {
      _bombCount = ((_bombCount < _maxBombCount) ? _maxBombCount : _bombCount);
      _timeReload = 1.5f;
    }
  if (input.getKey(_controls[DROPBOMB], false))
    dropBomb(clock);
  for (int i = TOP; i != NONE; i++)
    {
      if (input.getKey(_controls[static_cast<e_dir>(i)], false))
	{
	  moveTo(static_cast<e_dir>(i), clock);
	  return ;
	}
    }
  if (_hasToStop == true)
    {
      _model->setCurrentSubAnim("end", false);
      _hasToStop = false;
    }
  checkPlayerDeath();
}

void			Player::draw(gdl::AShader& shader, gdl::Clock const& clock)
{
  if (_isAnim)
    _frameRate += 1;
  if (_frameRate == _frameDuration)
    {
      _frameRate = 0;
      _isAnim = false;
    }
  _model->draw(shader, getTransformation(), clock.getElapsed());
}

void				Player::checkPlayerDeath()
{
  std::vector<AObj*>::iterator	it;

  if ((*_dynamicMap)[std::make_pair<float, float>(glm::round(_position.x), glm::round(_position.z))] == FIRE)
    {
      for (it = _objects->begin(); it != _objects->end(); ++it)
	{
	  if (*it == this)
	    {
	      _camera->unsetPlayer(_type);
	      _objects->erase(it);
	      --(*_alive);
	      delete (this);
	      break;
	    }
	}
    }
}

bool			Player::moveTo(const e_dir direction, gdl::Clock const &clock)
{
  glm::vec3		possibleTranslate = _directionVector[direction] * static_cast<float>(clock.getElapsed()) * _speed;
  e_dir			directionTmp;

  _hasToStop = true;
  if (!_isAnim && (_isAnim = true))
    _model->setCurrentSubAnim("move", false);
  if (checkCollision(_position + possibleTranslate))
    {
      _lastTranslate = translate(possibleTranslate);
    }
  else if ((directionTmp = checkAutoMove(direction)) != NONE)
    {
      possibleTranslate = _directionVector[directionTmp] * static_cast<float>(clock.getElapsed()) * _speed;
      if (checkCollision(_position + possibleTranslate))
	_lastTranslate = translate(possibleTranslate);
    }
  setRotate(_rotationVector[direction]);
  checkPlayerDeath();
  return true;
}

bool			Player::dropBomb(gdl::Clock const&)
{
  if ((*_dynamicMap)[std::make_pair<float, float>(glm::round(_position.x), glm::round(_position.z))] == EMPTY
      && _bombCount > 0)
    {
      AObj*	bomb = new Bomb(glm::round(_position.x),
				glm::round(_position.z),
				_objects,
				_dynamicMap,
				_bombLvl
				);
      bomb->initialize();
      _objects->push_back(bomb);
      _bombCount -= 1;
      _timeReload = 1.5f;
    }
  return true;
}

glm::vec3		Player::getLastTranslate()
{
  return _lastTranslate;
}

void			Player::clearLastTranslate()
{
  _lastTranslate = glm::vec3(0.0f, 0.0f, 0.0f);
}

e_dir			Player::checkAutoMove(const e_dir direction)
{
  e_obj			obj = (*_dynamicMap)[std::make_pair(glm::round(_position.x + _directionVector[direction].x),
							    glm::round(_position.z + _directionVector[direction].z))];
  if (canAutoMove(obj))
    {
      if (direction == LEFT || direction == RIGHT)
	{
	  if (abs(_position.z - static_cast<int>(_position.z)) - 0.5 < 0.5f)
	    return ((_position.z - static_cast<int>(_position.z) - 0.5 < 0) ? TOP : BOT);
	}
      else if (direction == TOP || direction == BOT)
	{
	  if (abs(_position.x - static_cast<int>(_position.x)) - 0.5 < 0.5f)
	    return ((_position.x - static_cast<int>(_position.x) - 0.5 < 0) ? LEFT : RIGHT);
	}
    }
  return (NONE);
}

void				Player::findBonusToTake(e_obj const toTest)
{
  std::vector<AObj*>::iterator	it;
  glm::vec3			pos;

  for (it = _objects->begin(); it != _objects->end(); ++it)
    {
      pos = (*it)->getPosition();
      if (pos.x == glm::round(_position.x) && pos.z == glm::round(_position.z))
	{
	  (this->*_actionBonus[toTest])();
	  delete (*it);
	  _objects->erase(it);
	  break ;
	}
    }
}

bool			Player::canAutoMove(e_obj const type)
{
  if (type == EMPTY
      || type == BOMB
      || type == FIRE
      || type == B_BOMBLVLBONUS
      || type == B_SPEEDBONUS
      || type == B_SPEEDMALUS)
    return true;
  return false;
}

bool			Player::checkIfCollide(e_obj const toTest)
{
  if (toTest == EMPTY
      || toTest == BOMB
      || toTest == FIRE)
    return false;
  if (toTest == B_BOMBLVLBONUS
      || toTest == B_BOMBNBBONUS
      || toTest == B_SPEEDBONUS
      || toTest == B_SPEEDMALUS)
    {
      findBonusToTake(toTest);
      return false;
    }
  return true;
}


void			Player::incrementBombLvl()
{
  _bombLvl += 1;
}

void			Player::incrementMaxBombCount()
{
  _maxBombCount += 1;
  _bombCount = _maxBombCount;
}

void			Player::decreaseSpeed()
{
  if (_speed >= 1.0f)
    _speed -= 0.3f;
}

void			Player::incrementSpeed()
{
  if (_speed <= 10.0f)
    _speed += 0.5f;
}

bool			Player::checkCollision(glm::vec3 possiblePos)
{
  e_obj			first;
  e_obj			second;
  e_obj			third;
  e_obj			fourth;

  first = (*_dynamicMap)[std::make_pair(glm::round(possiblePos.x + 0.4f), glm::round(possiblePos.z + 0.4f))];
  second = (*_dynamicMap)[std::make_pair(glm::round(possiblePos.x - 0.4f), glm::round(possiblePos.z + 0.4f))];
  third = (*_dynamicMap)[std::make_pair(glm::round(possiblePos.x + 0.4f), glm::round(possiblePos.z - 0.4f))];
  fourth = (*_dynamicMap)[std::make_pair(glm::round(possiblePos.x - 0.4f), glm::round(possiblePos.z - 0.4f))];
  if (checkIfCollide(first)
      || checkIfCollide(second)
      || checkIfCollide(third)
      || checkIfCollide(fourth))
    return false;
  return true;
}

void			Player::setCamera(Camera* camera)
{
  _camera = camera;
}
