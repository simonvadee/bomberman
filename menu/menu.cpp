#include "menu.h"
#include <QIcon>
#include <QtUiTools>
#include <iostream>
#include <string>
#include <fstream>
#include <QLabel>
#include <QSound>
#include "highscoremenu.h"
#include <sstream>
#include "Param.h"
#include "GameEngine.hh"
#include "MapConstructor.hh"
#include "Options.hh"
#include <cstdlib>

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    _soundMenu("song/dk.wav"),
    _soundGame("song/bomber.wav"),
    ui(new Ui::Menu)
{
    QPalette back;

    this->mode = 0;
    back.setBrush(this->backgroundRole(), QBrush(QImage("menuUi/background.jpeg")));
    this->setPalette(back);
    isExit = false;
    ui->setupUi(this);
    _soundMenu.play();
    _soundMenu.setLoops(-1);
    _soundMenu.loops();
}

Menu::~Menu()
{
    delete ui;
}



void        Menu::on_exitButton_clicked()
{
    mode = 4;
    isExit = true;
    QApplication::quit();
}

void         Menu::changeImg(const char *name)
{
    QPalette back;

    back.setBrush(this->backgroundRole(), QBrush(QImage(name)));
    this->setPalette(back);
}

void        Menu::on_highScoreButton_clicked()
{
    HighScoreMenu *widget = new HighScoreMenu;
    setCentralWidget(widget);

    mode = 3;
    QObject::connect(widget, &HighScoreMenu::homeSignal, this, &Menu::home);
    const char *img = "menuUi/HighScore.jpeg";
    this->changeImg(img);
    std::ifstream file("highScore", std::ios::in);
    if(file)
        {
            std::string ret;
            getline(file, ret);
            std::istringstream nbr(ret);
            int value;
            nbr >> value;
            widget->setLcdValue(value);
            file.close();
        }
    else
    {
        QString str = "don't have any highScore";
        QLabel *label = new QLabel(this);
        label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        label->setText(str);
        setCentralWidget(label);
    }
}

void        Menu::on_loadGameButton_clicked()
{
    loadMenu *widget = new loadMenu;
    const char *img = "menuUi/loadGame.jpeg";

    mode = 2;
    QObject::connect(widget, &loadMenu::loadGameSignal, this, &Menu::home);
    this->changeImg(img);
    this->setCentralWidget(widget);
}

void        Menu::on_newGameButton_clicked()
{
    newGameMenu *widget = new newGameMenu;
    const char *img = "menuUi/newGame.jpeg";

    mode = 1;
    QObject::connect(widget, &newGameMenu::newGameSignal, this, &Menu::home);
    QObject::connect(widget, &newGameMenu::soloSignal, this, &Menu::solo);
    QObject::connect(widget, &newGameMenu::multiSignal, this, &Menu::multi);
    QObject::connect(widget, &newGameMenu::playSignal, this, &Menu::play);
    QObject::connect(widget, &newGameMenu::xSignal, this, &Menu::xValue);
    QObject::connect(widget, &newGameMenu::iaSignal, this, &Menu::iaValue);
    this->changeImg(img);
    this->setCentralWidget(widget);
}

void        Menu::iaValue(int nb)
{
    std::cout << nb << std::endl;
    this->opt.setNbIa(nb);
}

void        Menu::xValue(int nb)
{
    if ((nb % 2) == 0)
        nb = nb - 1;
    this->opt.setX(nb);
}

void        Menu::home()
{
    QPalette back;

    back.setBrush(this->backgroundRole(), QBrush(QImage("menuUi/background.jpeg")));
    this->setPalette(back);
    ui->setupUi(this);
}

void       Menu::solo()
{
    QPalette back;

    opt.setIsMulti(false);
    back.setBrush(this->backgroundRole(), QBrush(QImage("menuUi/soloMode.jpeg")));
    this->setPalette(back);
}

void        Menu::multi()
{
    QPalette back;

    opt.setIsMulti(true);
    back.setBrush(this->backgroundRole(), QBrush(QImage("menuUi/multiMode.jpeg")));
    this->setPalette(back);
}

int         Menu::getMode()
{
        return (this->mode);
}

int    Menu::play()
{
    this->hide();
    _soundMenu.stop();
    _soundMenu.setLoops(-1);
    _soundMenu.loops();
    _soundGame.play();
    _soundGame.setLoops(-1);
    _soundGame.loops();

   int             nbPlayer = 1;

    if (opt.getIsMulti() == true)
    {
      nbPlayer = 2;
    }

    Options         options(nbPlayer, opt.getX(), opt.getX(), opt.getNbIa());
    MapConstructor	map(options.getSizeXMap(), options.getSizeYMap());
    GameEngine*		engine = new GameEngine(&options, map);

    try
      {
        if (engine->initialize() == false)
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
    while (engine->update() == true)
      engine->draw();
    delete engine;
    _soundGame.stop();
    _soundMenu.play();
    _soundMenu.setLoops(-1);
    _soundMenu.loops();
    this->show();
    return (EXIT_SUCCESS);
}
