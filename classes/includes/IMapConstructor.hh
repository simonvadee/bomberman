//
// IMapConstructor.hh for bomberman in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue May  5 14:11:11 2015 Aurélien GIRARDEAU
// Last update Thu May  7 16:59:53 2015 Arthur Ngo Van
//

#ifndef IMAPCONSTRUCTOR_HH_
# define IMAPCONSTRUCTOR_HH_

# include <string>

class		IMapConstructor
{
public:
  virtual ~IMapConstructor() {}

  virtual void			generateMap() = 0;
  virtual void			loadMap(std::string const& file) = 0;
};

#endif /* IMAPCONSTRUCTOR_HH_ */
