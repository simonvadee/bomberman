#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QSound>
#include "highscoremenu.h"
#include "loadmenu.h"
#include "newgamemenu.h"
#include "ui_menu.h"
#include "Param.h"
#include "Options.hh"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private:
    QSound              _soundMenu;
    QSound              _soundGame;
    Ui::Menu            *ui;
    bool                isExit;
    void                changeImg(const char *name);
    int                 mode;
    Param               opt;

public:
    int         getMode();
private slots:
    void on_exitButton_clicked();
    void on_highScoreButton_clicked();
    void on_loadGameButton_clicked();
    void on_newGameButton_clicked();

public slots:
    void    home();
    void    solo();
    void    multi();
    int     play();
    void    iaValue(int nb);
    void    xValue(int nb);
};

#endif // MENU_H
