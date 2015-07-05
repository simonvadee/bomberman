//
// BonusEngine.hh for bomberman in /home/girard_r/rendu/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Sat Jun  6 12:31:54 2015 Aurélien GIRARDEAU
// Last update Mon Jun  8 12:05:08 2015 Aurélien GIRARDEAU
//

#ifndef BONUS_ENGINE_HH
# define BONUS_ENGINE_HH

# include <vector>
# include <map>
# include "AObj.hh"
# include "BombNbBonus.hh"
# include "BombLvlBonus.hh"
# include "SpeedBonus.hh"
# include "SpeedMalus.hh"

class						BonusEngine
{
private :
  typedef AObj*					(BonusEngine::*createPtr)(std::pair<float, float> const&);

  std::map<e_obj, createPtr>			_mapCreate;

  std::vector<AObj*>				*_objects;
  std::map<e_obj, int>				_bonusCount;


  int						_mapX;
  int						_mapY;
  std::map<std::pair<float, float>, e_obj>	*_map;

public :
  BonusEngine(std::map<std::pair<float, float>, e_obj> *map, std::vector<AObj*> *obj, int x, int y);
  ~BonusEngine();
  bool						initialize();
  void						update();
  int						nbBonuses();
  int						countBonuses();
  void						resetCounter();
  e_obj						determBonus();
  void						addBonus(e_obj bonus);
  AObj						*createBombLvlBonus(std::pair<float, float> const&);
  AObj						*createBombNbBonus(std::pair<float, float> const&);
  AObj						*createSpeedBonus(std::pair<float, float> const&);
  AObj						*createSpeedMalus(std::pair<float, float> const&);
};

#endif
