#include "highscoremenu.h"
#include "ui_highscoremenu.h"

HighScoreMenu::HighScoreMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScoreMenu)
{
    ui->setupUi(this);
}

HighScoreMenu::~HighScoreMenu()
{
    delete ui;
}

void            HighScoreMenu::on_home_clicked()
{
    emit homeSignal();
}

void        HighScoreMenu::setLcdValue(int value)
{
    ui->lcdNumber->display(value);
}
