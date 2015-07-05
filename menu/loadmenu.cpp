#include "loadmenu.h"
#include "ui_loadmenu.h"
#include <QFileDialog>
#include <QMessageBox>

loadMenu::loadMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loadMenu)
{
    QPalette back;

    back.setBrush(this->backgroundRole(), QBrush(QImage("menuUi/loadGame.jpeg")));
    this->setPalette(back);
    ui->setupUi(this);
}

loadMenu::~loadMenu()
{
    delete ui;
}

void    loadMenu::on_home_clicked()
{
    emit loadGameSignal();
}

void    loadMenu::on_openSave_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open Save"), "~/Document", "All files (*.*);;");
    QMessageBox::information(this, tr("File Name"), fileName);
    this->saveName = fileName.toStdString();
}

std::string     loadMenu::getSaveName() const
{
    return (this->saveName);
}
