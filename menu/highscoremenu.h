#ifndef HIGHSCOREMENU_H
#define HIGHSCOREMENU_H

#include <QWidget>

namespace Ui {
class HighScoreMenu;
}

class HighScoreMenu : public QWidget
{
    Q_OBJECT

public:
    explicit HighScoreMenu(QWidget *parent = 0);
    ~HighScoreMenu();

private:
    Ui::HighScoreMenu *ui;

public:
    void        setLcdValue(int value);
private slots:
 void    on_home_clicked();
signals:
    void homeSignal();

};

#endif // HIGHSCOREMENU_H
