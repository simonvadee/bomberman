//
// AObjFactory.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Mon May 18 17:24:09 2015 Aurélien GIRARDEAU
// Last update Tue Jun  2 21:55:38 2015 Aurélien GIRARDEAU
//

#ifndef AOBJ_FACTORY_HH
# define AOBJ_FACTORY_HH

# include <map>
# include "AObj.hh"
# include "Wall.hh"
# include "Obstacle.hh"
# include "Player.hh"
# include "Board.hh"
# include "Limit.hh"

class				AObjFactory
{
private :
  typedef AObj*			(AObjFactory::*createPtr)(std::pair<int, int> const&);
  std::map<e_obj, createPtr>	_mapCreate;

public :
  AObjFactory();
  ~AObjFactory();
  AObj*		createAObj(e_obj, std::pair<int, int> const&);
private :
  AObjFactory(AObjFactory const&);
  AObjFactory&	operator=(AObjFactory const&);
  AObj*		createWall(std::pair<int, int> const&);
  AObj*		createObstacle(std::pair<int, int> const&);
  AObj*		createPlayer1(std::pair<int, int> const&);
  AObj*		createPlayer2(std::pair<int, int> const&);
  AObj*		createBoard(std::pair<int, int> const&);
  AObj*		createLimit(std::pair<int, int> const&);
  AObj*		createIA(std::pair<int, int> const&);
};

#endif
