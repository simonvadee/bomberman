//
// MapConstructor.hh for bomberman in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Wed May  6 11:22:46 2015 Aurélien GIRARDEAU
// Last update Sat Jun  6 12:50:37 2015 Aurélien GIRARDEAU
//

#ifndef MAPCONSTRUCTOR_HH_
# define MAPCONSTRUCTOR_HH_

# include <map>
# include <vector>
# include <iostream>
# include <cstdlib>
# include <unistd.h>
# include <fstream>
# include <ctime>
# include <algorithm>
# include <sys/types.h>
# include <sys/stat.h>
# include <string>
# include <fcntl.h>
# include "AObj.hh"
# include "IMapConstructor.hh"

class					MapConstructor : public IMapConstructor
{
private :
  int					_sizeX;
  int					_sizeY;
  int					_density;
  std::vector<std::pair<int, int> >	_dir;
  std::map<char, e_obj>			_corresp;
  std::map<std::pair<int,int>, int>	_map;
public:
  std::map<std::pair<int,int>, e_obj>	_finalMap;

public :
  MapConstructor(int sizeX, int sizeY);
  MapConstructor(std::string const &file, int sizeX = -1, int sizeY = -1);
  ~MapConstructor();

  void						objMapTochar();
  e_obj						whatsHere(int posX, int posY);
  void						intMapToObj();
  void						printRawMap();
  int						getSizeX() const;
  int						getSizeY() const;
  std::map<std::pair<int,int>, e_obj>*		getMap();
  std::map<std::pair<float,float>, e_obj>	getDynamicMap();

private:
  void					generateMap();
  void					loadMap(std::string const& file);
  void					makeCorrespondance();
  void					makeGates(int const value);
  void					createMap();
  bool					isValid(int const x, int const y, int const dir, int const value);
  void					findGate(int const i, int const j, int const value);
  bool					isOnePath();
  int					countValues(int const color);
  void					replaceColor(int const colorReplaced, int const copyColor);
  char					findKey(e_obj const type);
  void					convertLine(std::string const& input);
  void					randomizeObjects(int const density);
  void					transform();
};

#endif /* MAPCONSTRUCTOR_HH_ */
