//
// IA.hh for bomber in /home/ngo-va_a/rendu/bomberman/classes
//
// Made by Arthur Ngo Van
// Login   <ngo-va_a@epitech.net>
//
// Started on  Thu May  7 12:48:40 2015 Arthur Ngo Van
// Last update Sat Jun 13 16:15:00 2015 Aurélien GIRARDEAU
//

#ifndef IA_HH_
# define IA_HH_

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

# include "MapConstructor.hh"
# include "Way.hh"
# include "CubeColor.hh"

typedef enum
  {
    TOP = 0,
    RIGHT,
    BOT,
    LEFT,
    NONE,
    DROPBOMB,
    GETBONUS
  }						e_dir;

class						IA : public AObj
{
  typedef void                                  (IA::*actionBonus)();
private:
  std::pair<int,int>				_pos;
  float						_baseSpeed;
  float						_speed;
  float						_epsilon;
  bool						_inDanger;
  std::pair<float,float>			_realPos;
  std::pair<float,float>			_lastPos;
  bool						_isAnim;
  e_dir						_nextMove;
  bool						_onBomb;
  int						_bombLvl;
  float						_timeReload;
  int						_maxBombCount;
  int						_bombCount;
  gdl::Texture					_texture;
  gdl::Geometry					_geometry;
  std::map<e_obj, int>				_weightValue;
  std::deque<Way>				_ways;
  std::vector<std::pair<int,int> >		_dir;
  std::map<std::pair<int,int>, e_dir>		_trans;
  std::map<e_dir, glm::vec3>			_translate;
  gdl::Model					_model;
  std::pair<int, int>				_mapSize;
  int						_frameRate;
  int						_frameDuration;
  int						_validWays;
  std::map<std::pair<float, float>, e_obj>*	_dynamicMap;
  std::vector<AObj*>*				_objects;
  std::map<e_obj, actionBonus>                  _actionBonus;
  std::map<e_dir, glm::vec3>			_rotationVector;
  unsigned int*					_alive;

public:
  IA(std::pair<int,int> const& pos);
  IA(std::pair<int,int> const& pos, int humanTargetWeight, int iaTargetWeight, int obstacleTargetWeight);
  virtual ~IA() {};
  void						run();
  void						setAlive(unsigned int*);
  void						setDynamicMap(std::map<std::pair<float, float>, e_obj>* dMap);
  void						setObjectsContainer(std::vector<AObj*>* objects);
  void						setMapSize(int const x, int const y);

private:
  virtual void					findTarget(std::pair<int,int> actual, int depth);
  virtual bool					bomb();
  bool						goodDir(std::pair<int,int>& pos, std::pair<int,int>& add);
  void						initALL();
  bool						isWorthIt(std::pair<int,int>& pos);
  bool						wasAlreadyHere(std::pair<int,int> pos);
  void						dump();
  void						findBestTarget();
  virtual bool					initialize();
  virtual void					update(gdl::Clock const &clock, gdl::Input &input);
  virtual void					draw(gdl::AShader &shader,gdl::Clock const& clock);
  bool						isPosEqual(std::pair<int, int> const dir);
  bool						isEqual(float const real, int const dir);
  bool						isBetween(std::deque<std::pair<int, int> > main);
  float						fAbs(const float);
  e_dir						getNextMove(int const x, int const y);
  bool						isSameWay(std::deque<std::pair<int,int> > &next, std::deque<std::pair<int,int> > &last);
  bool						getBonus();
  void						incrementBombLvl();
  void						incrementMaxBombCount();
  void						decreaseSpeed();
  void						incrementSpeed();
  bool						isStraight(std::pair<int,int> &bomb, std::deque<std::pair<int,int> > &target);
  void						roundPositions();
  void						findClearWay();
  void						findOtherWay();
  bool						goodMove(e_dir const move);
  void						die();
  bool						isDead();
};

#endif /* IA_HH_ */
