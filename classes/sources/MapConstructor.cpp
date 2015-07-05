//
// MapConstructor.cpp for map in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue May  5 14:35:41 2015 Aurélien GIRARDEAU
// Last update Sat Jun  6 12:50:21 2015 Aurélien GIRARDEAU
//

#include "MapConstructor.hh"

MapConstructor::MapConstructor(int sizeX, int sizeY)
  : _sizeX(sizeX), _sizeY(sizeY), _density(35)
{

  if ((_sizeX < 11 && _sizeY < 11) || _sizeX % 2 != 1 || _sizeY % 2 != 1)
    throw BombermanError::MapSizeFailure("Wrong map size, try x > 10 && y > 10\n");
  srand(time(NULL));
  makeCorrespondance();
  generateMap();
}

MapConstructor::MapConstructor(std::string const& fileName, int sizeX, int sizeY)
  : _sizeX(sizeX), _sizeY(sizeY), _density(35)
{
  loadMap(fileName);
}

MapConstructor::~MapConstructor()
{
}

void				MapConstructor::makeCorrespondance()
{
  _dir.push_back(std::make_pair(0, -2));
  _dir.push_back(std::make_pair(2, 0));
  _dir.push_back(std::make_pair(0, 2));
  _dir.push_back(std::make_pair(-2, 0));
  _corresp[' '] = EMPTY;
  _corresp['M'] = PLAYER1;
  _corresp['W'] = PLAYER2;
  _corresp['X'] = WALL;
  _corresp['O'] = OBSTACLE;
  _corresp['o'] = BOMB;
  _corresp['I'] = BASIC_IA;
}

bool				MapConstructor::isValid(int const x, int const y, int const dir, int const value)
{
  if (x + _dir[dir].first < 0 || x + _dir[dir].first >= _sizeX || y + _dir[dir].second < 0 || y + _dir[dir].second >= _sizeY)
    return (false);
  if (_map[std::make_pair(x + _dir[dir].first, y + _dir[dir].second)] == _map[std::make_pair(x, y)] || countValues(_map[std::make_pair(x + _dir[dir].first, y + _dir[dir].second)]) < value)
    return (true);
  return (false);
}

int				MapConstructor::countValues(int const color)
{
  int				count = 0;

  for (std::map<std::pair<int,int>, int>::iterator it = _map.begin(); it != _map.end(); ++it)
    if (color == it->second)
      ++count;
  return (count);
}
void				MapConstructor::replaceColor(int const colorReplaced, int const copyColor)
{
  for (std::map<std::pair<int,int>, int>::iterator it = _map.begin(); it != _map.end(); ++it)
    if (it->second == colorReplaced)
      it->second = copyColor;
}

void				MapConstructor::findGate(int const i, int const j, int const value)
{
  int				random;
  int				max;

  if (countValues(_map[std::make_pair(i, j)]) < value)
    {
      random = rand() % 4;
      for (max = 0; max < 4; ++max)
	{
	  if (isValid(i, j, random, value))
	    {
	      _map[std::make_pair(i + _dir[random].first / 2, j + _dir[random].second / 2)] = _map[std::make_pair(i, j)];
	      replaceColor(_map[std::make_pair(i + _dir[random].first, j + _dir[random].second)], _map[std::make_pair(i, j)]);
	      break;
	    }
	  random = (random + 1) % 4;
	}
    }
}

bool				MapConstructor::isOnePath()
{
  int				i;
  int				j;
  int				color;

  color = _map[std::make_pair(0, 0)];
  for (i = 0; i < _sizeY; i += 2)
    {
      for (j = 0; j < _sizeX; j += 2)
	if (_map[std::make_pair(i, j)] != color && _map[std::make_pair(i, j)] != 0)
	  return (false);
    }
  return (true);
}

void				MapConstructor::makeGates(int const value)
{
  int				i;
  int				j;

  for (i = 0; i < _sizeY; i += 2)
    {
      for (j = 0; j < _sizeX; j += 2)
	findGate(i, j, value);
    }
  if (!isOnePath())
    makeGates(value + 2);
}

void				MapConstructor::createMap()
{
  int				count = 0;
  int				i;
  int				j;

  for (j = 0; j < _sizeY; ++j)
    {
      for (i = 0; i < _sizeX; ++i)
	{
	  if (i % 2 == 0 && j % 2 == 0)
	    _map[std::make_pair(j, i)] = ++count;
	  else
	    _map[std::make_pair(j, i)] = 0;
	}
    }
}

void				MapConstructor::randomizeObjects(int const density)
{
  for (std::map<std::pair<int,int>, e_obj>::iterator it = _finalMap.begin(); it != _finalMap.end(); ++it)
    {
      if (it->second == EMPTY && rand() % 100 < density)
	it->second = OBSTACLE;
    }
  _finalMap[std::make_pair(0, 0)] = EMPTY;
  _finalMap[std::make_pair(1, 0)] = EMPTY;
  _finalMap[std::make_pair(0, 1)] = EMPTY;
  _finalMap[std::make_pair(0, 2)] = EMPTY;
  _finalMap[std::make_pair(0, _sizeY - 1)] = EMPTY;
  _finalMap[std::make_pair(1, _sizeY - 1)] = EMPTY;
  _finalMap[std::make_pair(2, _sizeY - 1)] = EMPTY;
  _finalMap[std::make_pair(0, _sizeY - 2)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 1, 0)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 2, 0)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 1, 1)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 1, 2)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 1, _sizeY - 1)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 2, _sizeY - 1)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 1, _sizeY - 2)] = EMPTY;
  _finalMap[std::make_pair(_sizeX - 1, _sizeY - 3)] = EMPTY;
}

void				MapConstructor::transform()
{
  for (std::map<std::pair<int,int>,int>::iterator it = _map.begin(); it != _map.end(); ++it)
    {
      if (it->second != 0)
	it->second = 0;
      else
	it->second = 3;
    }
}

void				MapConstructor::generateMap()
{
  createMap();
  makeGates(2);
  transform();
  intMapToObj();
  randomizeObjects(_density);
}

char				MapConstructor::findKey(e_obj const type)
{
  std::string			error("Unknown object type '");

  for (std::map<char, e_obj>::iterator it = _corresp.begin(); it != _corresp.end(); ++it)
    {
      if (it->second == type)
	return (it->first);
    }
  error += type;
  error += "\'\n";
  throw BombermanError::CharacterUnknown(error);
  return ('b');
}

void				MapConstructor::objMapTochar()
{
  for (std::map<std::pair<int,int>, e_obj>::iterator it = _finalMap.begin(); it != _finalMap.end(); ++it)
    _map[std::make_pair(it->first.first, it->first.second)] = findKey(it->second);
}

void				MapConstructor::intMapToObj()
{
  for (std::map<std::pair<int,int>, int>::iterator it = _map.begin(); it != _map.end(); ++it)
    _finalMap[std::make_pair(it->first.first, it->first.second)] = (e_obj)it->second;
}

// void				MapConstructor::saveMap()
// {
//   for
// }

void				MapConstructor::convertLine(std::string const& input)
{
  std::string::const_iterator	it;
  int				x = 0;
  static int			y = 0;

  for (it = input.begin(); it != input.end(); ++it)
    {
      _finalMap[std::make_pair(x, y)] = _corresp[*it];
      ++x;
    }
  ++y;
}

void				MapConstructor::loadMap(std::string const& fileName)
{
  std::ifstream			myFile(fileName.c_str());
  std::string			line;

  if (!myFile.is_open())
    throw BombermanError::FileError(errno, ": file cannot be opened\n");
  while (getline(myFile, line))
    {
      convertLine(line);
    }
  myFile.close();
}

e_obj				MapConstructor::whatsHere(int posX, int posY)
{
  return (_finalMap[std::make_pair(posX, posY)]);
}

void				MapConstructor::printRawMap()
{
  for (int y = 0; y < _sizeY; y++)
    {
      for (int x = 0; x < _sizeX; x++)
	{
	  std::cout << _finalMap[std::make_pair(x, y)];
	}
    }
}

int				MapConstructor::getSizeX() const
{
  return _sizeX;
}

int				MapConstructor::getSizeY() const
{
  return _sizeY;
}

std::map<std::pair<int,int>, e_obj>*	MapConstructor::getMap()
{
  return &_finalMap;
}

std::map<std::pair<float,float>, e_obj>	MapConstructor::getDynamicMap()
{
  std::map<std::pair<int,int>, e_obj>::iterator	it;
  std::map<std::pair<float,float>, e_obj>	dMap;

  for (it = _finalMap.begin(); it != _finalMap.end(); ++it)
    {
      dMap[std::make_pair(static_cast<float>((it->first).first),
			  static_cast<float>((it->first).second))] = it->second;
    }

  // Set Limit on dynamic Map
  for (int x = -1; x <= _sizeX; ++x)
    {
      dMap[std::make_pair(static_cast<float>(x), -1.0f)] = LIMIT;
    }
  for (int x = -1; x <= _sizeX; ++x)
    {
      dMap[std::make_pair(static_cast<float>(x), static_cast<float>(_sizeY))] = LIMIT;
    }
  for (int y = -1; y <= _sizeY; ++y)
    {
      dMap[std::make_pair(-1.0f, static_cast<float>(y))] = LIMIT;
    }
  for (int y = -1; y <= _sizeY; ++y)
    {
      dMap[std::make_pair(static_cast<float>(_sizeX), static_cast<float>(y))] = LIMIT;
    }
  return dMap;
}
