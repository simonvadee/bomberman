/********************************************************************************
** Form generated from reading UI file 'highscoremenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCOREMENU_H
#define UI_HIGHSCOREMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighScoreMenu
{
public:
    QCommandLinkButton *home;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *HighScoreMenu)
    {
        if (HighScoreMenu->objectName().isEmpty())
            HighScoreMenu->setObjectName(QStringLiteral("HighScoreMenu"));
        HighScoreMenu->resize(800, 636);
        home = new QCommandLinkButton(HighScoreMenu);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(780, 10, 91, 41));
        QFont font;
        font.setFamily(QStringLiteral("Courier 10 Pitch"));
        font.setPointSize(12);
        home->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-Bomberman-Desktop_Qt_5_4_1_GCC_64bit-Debug/iconMenu/home.svg"), QSize(), QIcon::Normal, QIcon::Off);
        home->setIcon(icon);
        lcdNumber = new QLCDNumber(HighScoreMenu);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(80, 370, 301, 91));

        retranslateUi(HighScoreMenu);

        QMetaObject::connectSlotsByName(HighScoreMenu);
    } // setupUi

    void retranslateUi(QWidget *HighScoreMenu)
    {
        HighScoreMenu->setWindowTitle(QApplication::translate("HighScoreMenu", "Form", 0));
        home->setText(QApplication::translate("HighScoreMenu", "Home", 0));
    } // retranslateUi

};

namespace Ui {
    class HighScoreMenu: public Ui_HighScoreMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCOREMENU_H
