/****************************************************************************
** Meta object code from reading C++ file 'rigidbodyestab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DUMPViewer/GUI/tabs/rigidbodyestab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rigidbodyestab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rigidBodyesTab_t {
    QByteArrayData data[12];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rigidBodyesTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rigidBodyesTab_t qt_meta_stringdata_rigidBodyesTab = {
    {
QT_MOC_LITERAL(0, 0, 14), // "rigidBodyesTab"
QT_MOC_LITERAL(1, 15, 14), // "updateInfoSlot"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "addSlot"
QT_MOC_LITERAL(4, 39, 10), // "deleteSlot"
QT_MOC_LITERAL(5, 50, 14), // "bodyChangeSlot"
QT_MOC_LITERAL(6, 65, 15), // "nameChangedSlot"
QT_MOC_LITERAL(7, 81, 11), // "setMassSlot"
QT_MOC_LITERAL(8, 93, 5), // "value"
QT_MOC_LITERAL(9, 99, 17), // "setMassCenterSlot"
QT_MOC_LITERAL(10, 117, 11), // "setTypeSlot"
QT_MOC_LITERAL(11, 129, 4) // "type"

    },
    "rigidBodyesTab\0updateInfoSlot\0\0addSlot\0"
    "deleteSlot\0bodyChangeSlot\0nameChangedSlot\0"
    "setMassSlot\0value\0setMassCenterSlot\0"
    "setTypeSlot\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rigidBodyesTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x09 /* Protected */,
       3,    0,   55,    2, 0x09 /* Protected */,
       4,    0,   56,    2, 0x09 /* Protected */,
       5,    0,   57,    2, 0x09 /* Protected */,
       6,    0,   58,    2, 0x09 /* Protected */,
       7,    1,   59,    2, 0x09 /* Protected */,
       9,    0,   62,    2, 0x09 /* Protected */,
      10,    1,   63,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void rigidBodyesTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rigidBodyesTab *_t = static_cast<rigidBodyesTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateInfoSlot(); break;
        case 1: _t->addSlot(); break;
        case 2: _t->deleteSlot(); break;
        case 3: _t->bodyChangeSlot(); break;
        case 4: _t->nameChangedSlot(); break;
        case 5: _t->setMassSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setMassCenterSlot(); break;
        case 7: _t->setTypeSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rigidBodyesTab::staticMetaObject = {
    { &dTabBar::staticMetaObject, qt_meta_stringdata_rigidBodyesTab.data,
      qt_meta_data_rigidBodyesTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rigidBodyesTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rigidBodyesTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rigidBodyesTab.stringdata0))
        return static_cast<void*>(this);
    return dTabBar::qt_metacast(_clname);
}

int rigidBodyesTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = dTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
