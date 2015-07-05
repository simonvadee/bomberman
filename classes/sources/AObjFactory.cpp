//
// AObjFactory.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Mon May 18 17:27:09 2015 Aurélien GIRARDEAU
// Last update Tue Jun  2 21:55:47 2015 Aurélien GIRARDEAU
//

#include "AObjFactory.hh"

AObjFactory::AObjFactory()
{
  _mapCreate[WALL] = &AObjFactory::createWall;
  _mapCreate[OBSTACLE] = &AObjFactory::createObstacle;
  _mapCreate[PLAYER1] = &AObjFactory::createPlayer1;
  _mapCreate[PLAYER2] = &AObjFactory::createPlayer2;
  _mapCreate[BOARD] = &AObjFactory::createBoard;
  _mapCreate[LIMIT] = &AObjFactory::createLimit;
  _mapCreate[BASIC_IA] = &AObjFactory::createIA;
}

AObjFactory::~AObjFactory()
{
}

AObj*		AObjFactory::createAObj(e_obj type, std::pair<int, int> const& coord)
{
  return (this->*_mapCreate[type])(coord);
}

AObj*		AObjFactory::createWall(std::pair<int, int> const& coord)
{
  return new Wall(static_cast<float>(coord.first), static_cast<float>(coord.second));
}

AObj*		AObjFactory::createObstacle(std::pair<int, int> const& coord)
{
  return new Obstacle(static_cast<float>(coord.first), static_cast<float>(coord.second));
}

AObj*		AObjFactory::createPlayer1(std::pair<int, int> const& coord)
{
  return new Player(PLAYER1, static_cast<float>(coord.first), static_cast<float>(coord.second));
}

AObj*		AObjFactory::createPlayer2(std::pair<int, int> const& coord)
{
  return new Player(PLAYER2, static_cast<float>(coord.first), static_cast<float>(coord.second));
}

AObj*		AObjFactory::createBoard(std::pair<int, int> const& coord)
{
  return new Board(static_cast<float>(coord.first), static_cast<float>(coord.second));
}

AObj*		AObjFactory::createLimit(std::pair<int, int> const& coord)
{
  return new Limit(static_cast<float>(coord.first), static_cast<float>(coord.second));
}

AObj*		AObjFactory::createIA(std::pair<int, int> const& coord)
{
  return new IA(coord);
}
