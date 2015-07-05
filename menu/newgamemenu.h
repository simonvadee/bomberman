#ifndef NEWGAMEMENU_H
#define NEWGAMEMENU_H

#include <QWidget>
#include "menu.h"
#include "ui_newgamemenu.h"

namespace Ui {
class newGameMenu;
}

class newGameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit newGameMenu(QWidget *parent = 0);
    ~newGameMenu();

private:
    Ui::newGameMenu *ui;
    bool            isMulti;
    int             iaNumbers;
    std::string     mapName;
    bool            isRandom;

public:
    Ui::newGameMenu *getUi() const;
    int             getIaNumbers() const;
    bool            getIsMulti() const;
    std::string     getMapName() const;
    bool            getIsRandom() const;

private slots:
    void on_multiMode_clicked();
    void on_soloMode_clicked();
    void on_home_clicked();
    void on_random_clicked();
    void on_openMap_clicked();
    void on_play_clicked();
    void on_ia_valueChanged();
    void on_xSize_valueChanged();
signals:
    void newGameSignal();
    void multiSignal();
    void soloSignal();
    void playSignal();
    void iaSignal(int);
    void xSignal(int);
};

#endif // NEWGAMEMENU_H
