/********************************************************************************
** Form generated from reading UI file 'loadmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADMENU_H
#define UI_LOADMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loadMenu
{
public:
    QCommandLinkButton *home;
    QPushButton *openSave;

    void setupUi(QWidget *loadMenu)
    {
        if (loadMenu->objectName().isEmpty())
            loadMenu->setObjectName(QStringLiteral("loadMenu"));
        loadMenu->resize(900, 636);
        home = new QCommandLinkButton(loadMenu);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(800, 10, 91, 41));
        QFont font;
        font.setFamily(QStringLiteral("Courier 10 Pitch"));
        font.setPointSize(12);
        home->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-Bomberman-Desktop_Qt_5_4_1_GCC_64bit-Debug/iconMenu/home.svg"), QSize(), QIcon::Normal, QIcon::Off);
        home->setIcon(icon);
        openSave = new QPushButton(loadMenu);
        openSave->setObjectName(QStringLiteral("openSave"));
        openSave->setGeometry(QRect(250, 290, 321, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Bomberman"));
        font1.setPointSize(15);
        openSave->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-Bomberman-Desktop_Qt_5_4_1_GCC_64bit-Debug/iconMenu/Very Basic File.png"), QSize(), QIcon::Normal, QIcon::Off);
        openSave->setIcon(icon1);
        openSave->setIconSize(QSize(20, 20));

        retranslateUi(loadMenu);

        QMetaObject::connectSlotsByName(loadMenu);
    } // setupUi

    void retranslateUi(QWidget *loadMenu)
    {
        loadMenu->setWindowTitle(QApplication::translate("loadMenu", "Form", 0));
        home->setText(QApplication::translate("loadMenu", "Home", 0));
        openSave->setText(QApplication::translate("loadMenu", "Open Save", 0));
    } // retranslateUi

};

namespace Ui {
    class loadMenu: public Ui_loadMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADMENU_H
