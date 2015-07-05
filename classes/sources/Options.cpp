//
// Options.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Mon Jun  1 17:55:31 2015 Aurélien GIRARDEAU
// Last update Mon Jun  1 18:03:29 2015 Aurélien GIRARDEAU
//

#include "Options.hh"

Options::Options(int nbPlayers,
		 int sizeXMap,
		 int sizeYMap,
		 int nbIa,
		 float width,
		 float height)
  : _nbPlayers(nbPlayers),
    _sizeXMap(sizeXMap),
    _sizeYMap(sizeYMap),
    _nbIa(nbIa),
    _width(width),
    _height(height)
{
}

Options::~Options()
{
}

int		Options::getNbPlayers() const
{
  return _nbPlayers;
}

int		Options::getSizeXMap() const
{
  return _sizeXMap;
}

int		Options::getSizeYMap() const
{
  return _sizeYMap;
}

float		Options::getWidth() const
{
  return _width;
}

float		Options::getHeight() const
{
  return _height;
}

int		Options::getNbIa() const
{
  return _nbIa;
}

std::string	Options::getMapPath() const
{
  return _mapPath;
}

void	Options::setMapPath(std::string mapPath)
{
  _mapPath = mapPath;
}
