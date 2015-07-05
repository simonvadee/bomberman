//
// Player.hh for Bomberman in /home/oscar/rendu/bomberman/classes/includes
//
// Made by Oscar Morizet
// Login   <oscar@epitech.net>
//
// Started on  Tue May  5 15:32:29 2015 Oscar Morizet
// Last update Fri Jun 12 17:20:51 2015 Aurélien GIRARDEAU
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <map>
# include <Game.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include "AObj.hh"
# include "IA.hh"
# include "Bomb.hh"

class						Camera;

class						Player : public AObj
{
  typedef void					(Player::*actionBonus)();
private:
  std::map<e_dir, int>				_controls;
  int						_playerNum;
  int						_playerLevel;
  float						_posX;
  float						_posY;
  gdl::BasicShader*				_shader;
  gdl::Model*					_model;
  float						_speed;
  bool						_isAnim;
  bool						_hasToStop;
  int						_frameRate;
  std::map<std::pair<float, float>, e_obj>*	_dynamicMap;
  int						_frameDuration;
  glm::vec3					_lastTranslate;
  std::map<e_dir, glm::vec3>			_directionVector;
  std::map<e_dir, glm::vec3>			_rotationVector;
  std::vector<AObj*>*				_objects;
  std::map<e_obj, actionBonus>			_actionBonus;
  unsigned int*					_alive;

  // gestion bombes
  int						_maxBombCount;
  int						_bombCount;
  int						_bombLvl;
  float						_timeReload;
  Camera*					_camera;

public:
  Player(e_obj playerType, float posX, float posY);
  ~Player() {};

public:
  bool					initialize();
  void					update(gdl::Clock const&, gdl::Input&);
  void					draw(gdl::AShader&, gdl::Clock const&);
  void					customizeControls(const int, const int, const int, const int, const int);
  void					initControlsAsPlayerOne();
  void					initControlsAsPlayerTwo();
  bool					moveTo(const e_dir direction, gdl::Clock const &);
  bool					dropBomb(gdl::Clock const &);
  glm::vec3				getLastTranslate();
  e_dir					checkAutoMove(const e_dir);
  void					clearLastTranslate();
  void					setDynamicMap(std::map<std::pair<float, float>, e_obj>*);
  void					setObjectsContainer(std::vector<AObj*>*);
  void					setAlive(unsigned int*);
  void					setCamera(Camera*);

private :
  bool					checkIfCollide(const e_obj);
  bool					checkCollision(glm::vec3 possiblePos);
  void					findBonusToTake(const e_obj);
  void					incrementBombLvl();
  void					incrementMaxBombCount();
  void					incrementSpeed();
  void					decreaseSpeed();
  bool					canAutoMove(const e_obj);
  void					checkPlayerDeath();
};

# include "Camera.hh"
#endif					/* !PLAYER_HH_ */
