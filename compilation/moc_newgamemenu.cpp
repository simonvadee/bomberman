/****************************************************************************
** Meta object code from reading C++ file 'newgamemenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu/newgamemenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newgamemenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_newGameMenu_t {
    QByteArrayData data[16];
    char stringdata[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_newGameMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_newGameMenu_t qt_meta_stringdata_newGameMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "newGameMenu"
QT_MOC_LITERAL(1, 12, 13), // "newGameSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "multiSignal"
QT_MOC_LITERAL(4, 39, 10), // "soloSignal"
QT_MOC_LITERAL(5, 50, 10), // "playSignal"
QT_MOC_LITERAL(6, 61, 8), // "iaSignal"
QT_MOC_LITERAL(7, 70, 7), // "xSignal"
QT_MOC_LITERAL(8, 78, 20), // "on_multiMode_clicked"
QT_MOC_LITERAL(9, 99, 19), // "on_soloMode_clicked"
QT_MOC_LITERAL(10, 119, 15), // "on_home_clicked"
QT_MOC_LITERAL(11, 135, 17), // "on_random_clicked"
QT_MOC_LITERAL(12, 153, 18), // "on_openMap_clicked"
QT_MOC_LITERAL(13, 172, 15), // "on_play_clicked"
QT_MOC_LITERAL(14, 188, 18), // "on_ia_valueChanged"
QT_MOC_LITERAL(15, 207, 21) // "on_xSize_valueChanged"

    },
    "newGameMenu\0newGameSignal\0\0multiSignal\0"
    "soloSignal\0playSignal\0iaSignal\0xSignal\0"
    "on_multiMode_clicked\0on_soloMode_clicked\0"
    "on_home_clicked\0on_random_clicked\0"
    "on_openMap_clicked\0on_play_clicked\0"
    "on_ia_valueChanged\0on_xSize_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newGameMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       7,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   94,    2, 0x08 /* Private */,
       9,    0,   95,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void newGameMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        newGameMenu *_t = static_cast<newGameMenu *>(_o);
        switch (_id) {
        case 0: _t->newGameSignal(); break;
        case 1: _t->multiSignal(); break;
        case 2: _t->soloSignal(); break;
        case 3: _t->playSignal(); break;
        case 4: _t->iaSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->xSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_multiMode_clicked(); break;
        case 7: _t->on_soloMode_clicked(); break;
        case 8: _t->on_home_clicked(); break;
        case 9: _t->on_random_clicked(); break;
        case 10: _t->on_openMap_clicked(); break;
        case 11: _t->on_play_clicked(); break;
        case 12: _t->on_ia_valueChanged(); break;
        case 13: _t->on_xSize_valueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (newGameMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newGameMenu::newGameSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (newGameMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newGameMenu::multiSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (newGameMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newGameMenu::soloSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (newGameMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newGameMenu::playSignal)) {
                *result = 3;
            }
        }
        {
            typedef void (newGameMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newGameMenu::iaSignal)) {
                *result = 4;
            }
        }
        {
            typedef void (newGameMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&newGameMenu::xSignal)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject newGameMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_newGameMenu.data,
      qt_meta_data_newGameMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *newGameMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newGameMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_newGameMenu.stringdata))
        return static_cast<void*>(const_cast< newGameMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int newGameMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void newGameMenu::newGameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void newGameMenu::multiSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void newGameMenu::soloSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void newGameMenu::playSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void newGameMenu::iaSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void newGameMenu::xSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
