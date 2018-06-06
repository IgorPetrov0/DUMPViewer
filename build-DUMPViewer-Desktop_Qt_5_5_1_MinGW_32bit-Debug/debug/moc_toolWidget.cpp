/****************************************************************************
** Meta object code from reading C++ file 'toolWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DUMPViewer/GUI/toolWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_toolWidget_t {
    QByteArrayData data[11];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_toolWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_toolWidget_t qt_meta_stringdata_toolWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "toolWidget"
QT_MOC_LITERAL(1, 11, 10), // "updateInfo"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 22), // "graphicTabSelectedSlot"
QT_MOC_LITERAL(4, 46, 5), // "index"
QT_MOC_LITERAL(5, 52, 16), // "LODTabDeleteSlot"
QT_MOC_LITERAL(6, 69, 8), // "tabIndex"
QT_MOC_LITERAL(7, 78, 9), // "LODNumber"
QT_MOC_LITERAL(8, 88, 14), // "updateInfoSlot"
QT_MOC_LITERAL(9, 103, 15), // "showGraphicSlot"
QT_MOC_LITERAL(10, 119, 7) // "checked"

    },
    "toolWidget\0updateInfo\0\0graphicTabSelectedSlot\0"
    "index\0LODTabDeleteSlot\0tabIndex\0"
    "LODNumber\0updateInfoSlot\0showGraphicSlot\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_toolWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x09 /* Protected */,
       5,    2,   43,    2, 0x09 /* Protected */,
       8,    0,   48,    2, 0x09 /* Protected */,
       9,    1,   49,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void toolWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        toolWidget *_t = static_cast<toolWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateInfo(); break;
        case 1: _t->graphicTabSelectedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->LODTabDeleteSlot((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: _t->updateInfoSlot(); break;
        case 4: _t->showGraphicSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (toolWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&toolWidget::updateInfo)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject toolWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_toolWidget.data,
      qt_meta_data_toolWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *toolWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *toolWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_toolWidget.stringdata0))
        return static_cast<void*>(const_cast< toolWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int toolWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void toolWidget::updateInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
