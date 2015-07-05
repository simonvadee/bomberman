#include "newgamemenu.h"
#include "ui_newgamemenu.h"
#include "menu.h"
#include <QFileDialog>
#include <QMessageBox>

newGameMenu::newGameMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newGameMenu)
{
    QPalette back;

    back.setBrush(this->backgroundRole(), QBrush(QImage("menuUi/newGame.jpeg")));
    this->setPalette(back);
    this->isRandom = false;
    this->isMulti = false;
    this->iaNumbers = 0;
    ui->setupUi(this);
    this->ui->ia->setMaximum(2);
    this->ui->xSize->setMaximum(40);
    this->ui->xSize->setMinimum(11);

}

newGameMenu::~newGameMenu()
{
    delete ui;
}

Ui::newGameMenu         *newGameMenu::getUi() const
{
    return (this->ui);
}

int         newGameMenu::getIaNumbers()const
{
    return (this->iaNumbers);
}

bool        newGameMenu::getIsMulti() const
{
    return (this->isMulti);
}

std::string     newGameMenu::getMapName() const
{
    return (this->mapName);
}

bool            newGameMenu::getIsRandom() const
{
    return (this->isRandom);
}

void        newGameMenu::on_multiMode_clicked()
{
    this->isMulti = true;
    emit multiSignal();
}

void        newGameMenu::on_soloMode_clicked()
{
    this->isMulti = false;
    emit soloSignal();
}

void       newGameMenu::on_home_clicked()
{
    emit newGameSignal();
}

void       newGameMenu::on_openMap_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open Map"), "~/Document", "All files (*.*);;");
    QMessageBox::information(this, tr("File Name"), fileName);
    this->mapName = fileName.toStdString();
}

void       newGameMenu::on_random_clicked()
{
    this->isRandom = true;
}

void       newGameMenu::on_play_clicked()
{
    emit playSignal();
}

void        newGameMenu::on_ia_valueChanged()
{
    emit iaSignal(this->ui->ia->value());
}

void        newGameMenu::on_xSize_valueChanged()
{
    emit xSignal(this->ui->xSize->value());
}

