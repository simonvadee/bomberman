//
// GameEngine.hh for bomberman in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue May  5 12:42:05 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:58:52 2015 Aurélien GIRARDEAU
//

#ifndef GAME_ENGINE_HH_
# define GAME_ENGINE_HH_

# include <OpenGL.hh>
# include <Game.hh>
# include <SdlContext.hh>
# include <BasicShader.hh>
# include <vector>
# include "AObj.hh"
# include "MapConstructor.hh"
# include "IA.hh"
# include "AObjFactory.hh"
# include "Camera.hh"
# include "Player.hh"
# include "Options.hh"
# include "AssetsManager.hh"
# include "BonusEngine.hh"
# include "SkyBox.hh"
# include "GameOver.hh"

class						GameEngine : public gdl::Game
{
private :
  Options*					_options;
  MapConstructor				_map;
  std::map<std::pair<float, float>, e_obj>	_dynamicMap;
  Camera					_camera;
  gdl::SdlContext				_context;
  gdl::Clock					_clock;
  gdl::Input					_input;
  gdl::BasicShader				_shader;
  std::vector<AObj*>				_objects;
  std::vector<AObj*>				_limits;
  AObjFactory					_factory;
  BonusEngine					_bonuses;
  unsigned int					_alive;

public :
  GameEngine(Options*, MapConstructor const&);
  ~GameEngine();
  virtual bool		initialize();
  virtual bool		update();
  virtual void		draw();

private :
  void			initMap();
  void			initIA(int const nbIA);
  void			initPlayers();
  void			initBoardAndLimits();
  bool			checkAlive();
  bool			gameOver();
  int			countIA();
};

#endif /* !GAME_ENGINE_HH_ */
