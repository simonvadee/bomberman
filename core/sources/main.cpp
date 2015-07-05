//
// main.cpp for bomberman in /home/girard_r/Documents/cpp_bomberman
//
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
//
// Started on  Tue May  5 15:18:20 2015 Aurélien GIRARDEAU
// Last update Wed Jun  3 12:53:26 2015 Aurélien GIRARDEAU
//

#include <cstdlib>
#include "GameEngine.hh"
#include "MapConstructor.hh"
#include "Options.hh"

int			main()
{
  // fill Options with Menu
  Options		options;
  MapConstructor	map(options.getSizeXMap(), options.getSizeYMap());
  GameEngine		engine(&options, map);

  try
    {
      if (engine.initialize() == false)
	return (EXIT_FAILURE);
    }
  catch (BombermanError::ShaderBuildingFailure error)
    {
      std::cerr << error.what();
      return (EXIT_FAILURE);
    }
  catch (BombermanError::SubAnimFailure error)
    {
      std::cerr << error.what();
      return (EXIT_FAILURE);
    }
  catch (BombermanError::ModelLoadFailure error)
    {
      std::cerr << error.what();
      return (EXIT_FAILURE);
    }
  catch (BombermanError::TextureLoadFailure error)
    {
      std::cerr << error.what();
      return (EXIT_FAILURE);
    }
  catch (BombermanError::MapSizeFailure error)
    {
      std::cerr << error.what();
      return (EXIT_FAILURE);
    }
  catch (BombermanError::FileError error)
    {
      std::cerr << error.what();
      return (EXIT_FAILURE);
    }
  catch (BombermanError::CharacterUnknown error)
    {
      std::cerr << error.what();
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return (EXIT_SUCCESS);
}
