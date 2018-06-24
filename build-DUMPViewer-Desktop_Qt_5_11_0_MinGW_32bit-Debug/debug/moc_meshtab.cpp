/****************************************************************************
** Meta object code from reading C++ file 'meshtab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DUMPViewer/GUI/tabs/meshtab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meshtab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_meshTab_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_meshTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_meshTab_t qt_meta_stringdata_meshTab = {
    {
QT_MOC_LITERAL(0, 0, 7), // "meshTab"
QT_MOC_LITERAL(1, 8, 10), // "meshLoaded"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 22), // "editabelGraphicObject*"
QT_MOC_LITERAL(4, 43, 4), // "mesh"
QT_MOC_LITERAL(5, 48, 11) // "meshDeleted"

    },
    "meshTab\0meshLoaded\0\0editabelGraphicObject*\0"
    "mesh\0meshDeleted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_meshTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x09 /* Protected */,
       5,    0,   27,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void meshTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        meshTab *_t = static_cast<meshTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->meshLoaded((*reinterpret_cast< editabelGraphicObject*(*)>(_a[1]))); break;
        case 1: _t->meshDeleted(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject meshTab::staticMetaObject = {
    { &dTabBar::staticMetaObject, qt_meta_stringdata_meshTab.data,
      qt_meta_data_meshTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *meshTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *meshTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_meshTab.stringdata0))
        return static_cast<void*>(this);
    return dTabBar::qt_metacast(_clname);
}

int meshTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = dTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
