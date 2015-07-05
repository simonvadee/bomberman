//
// Options.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Mon Jun  1 17:55:08 2015 Aurélien GIRARDEAU
// Last update Wed Jun 10 16:25:23 2015 Aurélien GIRARDEAU
//

#include <iostream>

#ifndef OPTIONS_HH_
# define OPTIONS_HH_

class		Options
{
private :
  int		_nbPlayers;
  int		_sizeXMap;
  int		_sizeYMap;
  int		_nbIa;
  float		_width;
  float		_height;
  std::string	_mapPath;
public :
  Options(int nbPlayers = 2,
	  int sizeXMap = 19,
	  int sizeYMap = 19,
	  int nbIa = 0,
	  float _width = 1600.0f,
	  float _height = 900.0f);
  ~Options();
  int           getNbPlayers() const;
  int           getSizeXMap() const;
  int           getSizeYMap() const;
  int           getNbIa() const;
  float         getWidth() const;
  float         getHeight() const;
  std::string	getMapPath() const;

  void          setMapPath(std::string mapPath);
private :
  Options&	operator=(Options const&);
  Options(Options const&);
};

#endif
