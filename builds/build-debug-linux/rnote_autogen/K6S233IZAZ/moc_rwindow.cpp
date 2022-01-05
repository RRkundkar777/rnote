/****************************************************************************
** Meta object code from reading C++ file 'rwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/rwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RWindow_t {
    QByteArrayData data[14];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RWindow_t qt_meta_stringdata_RWindow = {
    {
QT_MOC_LITERAL(0, 0, 7), // "RWindow"
QT_MOC_LITERAL(1, 8, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(4, 56, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(5, 80, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(6, 107, 26), // "on_actionSupport_triggered"
QT_MOC_LITERAL(7, 134, 35), // "on_tabWidget_Note_tabCloseReq..."
QT_MOC_LITERAL(8, 170, 5), // "index"
QT_MOC_LITERAL(9, 176, 31), // "on_tabWidget_Note_tabBarClicked"
QT_MOC_LITERAL(10, 208, 23), // "on_actionFont_triggered"
QT_MOC_LITERAL(11, 232, 23), // "on_actionDark_triggered"
QT_MOC_LITERAL(12, 256, 24), // "on_actionLight_triggered"
QT_MOC_LITERAL(13, 281, 26) // "on_actionMonokai_triggered"

    },
    "RWindow\0on_actionNew_triggered\0\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionSupport_triggered\0"
    "on_tabWidget_Note_tabCloseRequested\0"
    "index\0on_tabWidget_Note_tabBarClicked\0"
    "on_actionFont_triggered\0on_actionDark_triggered\0"
    "on_actionLight_triggered\0"
    "on_actionMonokai_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RWindow *_t = static_cast<RWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionNew_triggered(); break;
        case 1: _t->on_actionOpen_triggered(); break;
        case 2: _t->on_actionSave_triggered(); break;
        case 3: _t->on_actionSave_As_triggered(); break;
        case 4: _t->on_actionSupport_triggered(); break;
        case 5: _t->on_tabWidget_Note_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_tabWidget_Note_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_actionFont_triggered(); break;
        case 8: _t->on_actionDark_triggered(); break;
        case 9: _t->on_actionLight_triggered(); break;
        case 10: _t->on_actionMonokai_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject RWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RWindow.data,
      qt_meta_data_RWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
