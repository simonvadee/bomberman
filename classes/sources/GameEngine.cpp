//
// GameEngine.cpp for bomberman in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue May  5 12:47:56 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 17:42:31 2015 Aurélien GIRARDEAU
//

#include <utility>
#include "GameEngine.hh"

GameEngine::GameEngine(Options* options,
		       MapConstructor const& map)
  : _options(options),
    _map(map),
    _dynamicMap(_map.getDynamicMap()),
    _camera(options->getNbPlayers(), options->getWidth(), options->getHeight()),
    _bonuses(&_dynamicMap, &_objects, _map.getSizeX(), _map.getSizeY()),
    _alive(1)
{
}

GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
  for (size_t i = 0; i < _limits.size(); ++i)
    delete _limits[i];
  AssetsManager::destroyAssetsManager();
  _context.stop();
}

bool		GameEngine::initialize()
{
  if (!_context.start(_options->getWidth(), _options->getHeight(), "MadBomberMax"))
    return (false);
  glEnable(GL_DEPTH_TEST);
  AssetsManager::instanciateAssetsManager();
  if (!_shader.load("./libgdl/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./libgdl/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    throw BombermanError::ShaderBuildingFailure("Could not build shader correctly\n");

  _shader.bind();
  _shader.setUniform("view", _camera.getTransformation());
  _shader.setUniform("projection", _camera.getProjection());

  initMap();
  initBoardAndLimits();
  initPlayers();
  // initIA(_options->getNbIa());
  _bonuses.initialize();
  _camera.initialize(&_shader);
  return (true);
}

void		GameEngine::initBoardAndLimits()
{
  std::pair<int, int>	mapSize(_map.getSizeX(), _map.getSizeY());
  AObj*			board = _factory.createAObj(BOARD, mapSize);
  AObj*			limits = _factory.createAObj(LIMIT, mapSize);
  AObj*			skyBox = new SkyBox(100.0f, mapSize);

  skyBox->initialize();
  board->initialize();
  limits->initialize();
  _limits.push_back(board);
  _limits.push_back(limits);
  _limits.push_back(skyBox);
}

void		GameEngine::initMap()
{
  for (std::map<std::pair<int, int>, e_obj>::iterator it = _map.getMap()->begin(); it != _map.getMap()->end(); ++it)
    {
      if (it->second != EMPTY)
	{
	  AObj* obj = _factory.createAObj(it->second, it->first);
	  if (obj == NULL || obj->initialize() == false)
	    exit(0);
	  _objects.push_back(obj);
	}
    }
}

void		GameEngine::initIA(int const nbIA)
{
  std::pair<int, int>		pos;

  for (int i = 0; i < nbIA; ++i)
    {
      if (i == 0)
	pos = std::make_pair(0, _map.getSizeY() - 1);
      else
	pos = std::make_pair(_map.getSizeX() - 1, 0);

      AObj*	newIA = _factory.createAObj(BASIC_IA, pos);
      reinterpret_cast<IA*>(newIA)->setAlive(&_alive);
      reinterpret_cast<IA*>(newIA)->setDynamicMap(&_dynamicMap);
      reinterpret_cast<IA*>(newIA)->setObjectsContainer(&_objects);
      reinterpret_cast<IA*>(newIA)->setMapSize(_map.getSizeX(), _map.getSizeY());
      newIA->initialize();
      _objects.push_back(newIA);
      _alive += 1;
    }
}

void		GameEngine::initPlayers()
{
  const		std::pair<int, int> playerOnePos(0, 0);
  const		std::pair<int, int> playerTwoPos(_map.getSizeX() - 1, _map.getSizeY() - 1);

  AObj* playerOne = _factory.createAObj(PLAYER1, playerOnePos);
  AObj* playerTwo = _factory.createAObj(PLAYER2, playerTwoPos);

  _camera.setPlayer(PLAYER1, reinterpret_cast<Player*>(playerOne));
  reinterpret_cast<Player*>(playerOne)->setDynamicMap(&_dynamicMap);
  reinterpret_cast<Player*>(playerOne)->setObjectsContainer(&_objects);
  reinterpret_cast<Player*>(playerOne)->setAlive(&_alive);
  reinterpret_cast<Player*>(playerOne)->setCamera(&_camera);
  playerOne->initialize();
  _objects.push_back(playerOne);
  if (_options->getNbPlayers() == 2)
    {
      _alive += 1;
      _camera.setPlayer(PLAYER2, reinterpret_cast<Player*>(playerTwo));
      reinterpret_cast<Player*>(playerTwo)->setDynamicMap(&_dynamicMap);
      reinterpret_cast<Player*>(playerTwo)->setObjectsContainer(&_objects);
      reinterpret_cast<Player*>(playerTwo)->setAlive(&_alive);
      reinterpret_cast<Player*>(playerTwo)->setCamera(&_camera);
      playerTwo->initialize();
      _objects.push_back(playerTwo);
    }
}

int		GameEngine::countIA()
{
  int		ret = 0;

  for (std::vector<AObj*>::iterator it = _objects.begin(); it != _objects.end(); ++it)
    {
      if ((*it)->getType() == BASIC_IA)
	++ret;
    }
  return ret;
}

bool		GameEngine::checkAlive()
{
  if ((countIA() == 0 && _alive == 1)
      || (_alive - countIA() == 0))
    return false;
  return true;
}

bool		GameEngine::gameOver()
{
  AObj*		gameOver = new GameOver();

  glm::mat4 projection = glm::perspective(60.0f, _options->getWidth() / _options->getHeight(), 0.1f, 200.0f);
  glm::mat4 transformation = glm::lookAt(glm::vec3(0.0f, 10.0f, 0.1f),
					 glm::vec3(0.0f, 0.0f, 0.0f),
					 glm::vec3(0.0f, 1.0f, 0.0f));
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  gameOver->initialize();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  gameOver->draw(_shader, _clock);
  _context.flush();
  sleep(4);
  delete gameOver;
  return false;
}

bool		GameEngine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return (false);
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  if (!checkAlive())
    return gameOver();
  _bonuses.update();
  _camera.update(_input);
  return (true);
}

void		GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _limits.size(); ++i)
    _limits[i]->draw(_shader, _clock);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _context.flush();
}
