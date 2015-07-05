#ifndef LOADMENU_H
#define LOADMENU_H

#include <QWidget>

namespace Ui {
class loadMenu;
}

class loadMenu : public QWidget
{
    Q_OBJECT

public:
    explicit loadMenu(QWidget *parent = 0);
    ~loadMenu();

private:
    Ui::loadMenu *ui;
    std::string  saveName;

public:
    Ui::loadMenu *getUi() const;
    std::string  getSaveName() const;

private slots:
    void    on_home_clicked();
    void    on_openSave_clicked();
signals:
    void loadGameSignal();
};

#endif // LOADMENU_H
