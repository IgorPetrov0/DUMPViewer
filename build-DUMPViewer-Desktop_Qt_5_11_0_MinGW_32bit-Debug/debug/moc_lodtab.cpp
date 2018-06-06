/****************************************************************************
** Meta object code from reading C++ file 'lodtab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DUMPViewer/GUI/tabs/lodtab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lodtab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LODTab_t {
    QByteArrayData data[11];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LODTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LODTab_t qt_meta_stringdata_LODTab = {
    {
QT_MOC_LITERAL(0, 0, 6), // "LODTab"
QT_MOC_LITERAL(1, 7, 12), // "deleteSignal"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "tabNumber"
QT_MOC_LITERAL(4, 31, 9), // "LODNumber"
QT_MOC_LITERAL(5, 41, 8), // "loadSlot"
QT_MOC_LITERAL(6, 50, 10), // "deleteSlot"
QT_MOC_LITERAL(7, 61, 14), // "setLodDistance"
QT_MOC_LITERAL(8, 76, 5), // "value"
QT_MOC_LITERAL(9, 82, 18), // "moveToDistanceSlot"
QT_MOC_LITERAL(10, 101, 14) // "updateInfoSlot"

    },
    "LODTab\0deleteSignal\0\0tabNumber\0LODNumber\0"
    "loadSlot\0deleteSlot\0setLodDistance\0"
    "value\0moveToDistanceSlot\0updateInfoSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LODTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   49,    2, 0x09 /* Protected */,
       6,    0,   50,    2, 0x09 /* Protected */,
       7,    1,   51,    2, 0x09 /* Protected */,
       9,    0,   54,    2, 0x09 /* Protected */,
      10,    0,   55,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LODTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LODTab *_t = static_cast<LODTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteSignal((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->loadSlot(); break;
        case 2: _t->deleteSlot(); break;
        case 3: _t->setLodDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->moveToDistanceSlot(); break;
        case 5: _t->updateInfoSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LODTab::*)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LODTab::deleteSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LODTab::staticMetaObject = {
    { &dTabBar::staticMetaObject, qt_meta_stringdata_LODTab.data,
      qt_meta_data_LODTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LODTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LODTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LODTab.stringdata0))
        return static_cast<void*>(this);
    return dTabBar::qt_metacast(_clname);
}

int LODTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = dTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LODTab::deleteSignal(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
