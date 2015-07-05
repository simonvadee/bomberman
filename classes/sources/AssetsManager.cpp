//
// AssetsManager.cpp for bomberman in /home/girard_r/rendu/cpp_bomberman
// 
// Made by Aurélien GIRARDEAU
// Login   <girard_r@epitech.net>
// 
// Started on  Wed Jun  3 11:45:39 2015 Aurélien GIRARDEAU
// Last update Sat Jun 13 16:32:36 2015 Aurélien GIRARDEAU
//

#include "AssetsManager.hh"

AssetsManager*	AssetsManager::_assetsManager = NULL;

AssetsManager::AssetsManager()
{
  _bombModel = new gdl::Model();
  _charOneModel = new gdl::Model();
  _charTwoModel = new gdl::Model();
  _explosionModel = new gdl::Model();
  _bombModel->load("./libgdl/assets/bomb.fbx");
  _charOneModel->load("./libgdl/assets/marvin.fbx");
  _charTwoModel->load("./libgdl/assets/marvin.fbx");
  _explosionModel->load("./libgdl/assets/fire.fbx");
}

AssetsManager::~AssetsManager()
{
  delete _bombModel;
  delete _charOneModel;
  delete _charTwoModel;
  delete _explosionModel;
}

void		AssetsManager::instanciateAssetsManager()
{
  if (_assetsManager == NULL)
    _assetsManager = new AssetsManager();
}

void		AssetsManager::destroyAssetsManager()
{
  if (_assetsManager != NULL)
    {
      delete _assetsManager;
      _assetsManager = NULL;
    }
}

gdl::Model*	AssetsManager::getBombModel()
{
  return (_assetsManager == NULL ? NULL :_assetsManager->_bombModel);
}

gdl::Model*	AssetsManager::getCharacterOneModel()
{
  return (_assetsManager == NULL ? NULL : _assetsManager->_charOneModel);
}

gdl::Model*	AssetsManager::getCharacterTwoModel()
{
  return (_assetsManager == NULL ? NULL : _assetsManager->_charTwoModel);
}

gdl::Model*	AssetsManager::getFireModel()
{
  return (_assetsManager == NULL ? NULL : _assetsManager->_explosionModel);
}
