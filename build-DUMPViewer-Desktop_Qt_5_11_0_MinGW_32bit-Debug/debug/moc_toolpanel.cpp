/****************************************************************************
** Meta object code from reading C++ file 'toolpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DUMPViewer/GUI/toolpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_toolPanel_t {
    QByteArrayData data[20];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_toolPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_toolPanel_t qt_meta_stringdata_toolPanel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "toolPanel"
QT_MOC_LITERAL(1, 10, 14), // "openPhisicMesh"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "fileName"
QT_MOC_LITERAL(4, 35, 15), // "openGraphicMesh"
QT_MOC_LITERAL(5, 51, 11), // "numberOfLOD"
QT_MOC_LITERAL(6, 63, 18), // "showHidePhisicMesh"
QT_MOC_LITERAL(7, 82, 4), // "show"
QT_MOC_LITERAL(8, 87, 19), // "showHideGraphicMesh"
QT_MOC_LITERAL(9, 107, 14), // "setLODDistance"
QT_MOC_LITERAL(10, 122, 8), // "distance"
QT_MOC_LITERAL(11, 131, 18), // "moveMeshToDistance"
QT_MOC_LITERAL(12, 150, 18), // "returnLastDistance"
QT_MOC_LITERAL(13, 169, 8), // "openSlot"
QT_MOC_LITERAL(14, 178, 4), // "name"
QT_MOC_LITERAL(15, 183, 15), // "setDistanceSlot"
QT_MOC_LITERAL(16, 199, 22), // "moveMeshToDistanceSlot"
QT_MOC_LITERAL(17, 222, 7), // "checked"
QT_MOC_LITERAL(18, 230, 23), // "showHideGraphicMeshSlot"
QT_MOC_LITERAL(19, 254, 22) // "showHidePhisicMeshSlot"

    },
    "toolPanel\0openPhisicMesh\0\0fileName\0"
    "openGraphicMesh\0numberOfLOD\0"
    "showHidePhisicMesh\0show\0showHideGraphicMesh\0"
    "setLODDistance\0distance\0moveMeshToDistance\0"
    "returnLastDistance\0openSlot\0name\0"
    "setDistanceSlot\0moveMeshToDistanceSlot\0"
    "checked\0showHideGraphicMeshSlot\0"
    "showHidePhisicMeshSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_toolPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    2,   77,    2, 0x06 /* Public */,
       6,    1,   82,    2, 0x06 /* Public */,
       8,    1,   85,    2, 0x06 /* Public */,
       9,    2,   88,    2, 0x06 /* Public */,
      11,    0,   93,    2, 0x06 /* Public */,
      12,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   95,    2, 0x09 /* Protected */,
      15,    1,   98,    2, 0x09 /* Protected */,
      16,    1,  101,    2, 0x09 /* Protected */,
      18,    1,  104,    2, 0x09 /* Protected */,
      19,    1,  107,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,   10,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,   17,

       0        // eod
};

void toolPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        toolPanel *_t = static_cast<toolPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openPhisicMesh((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->openGraphicMesh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->showHidePhisicMesh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showHideGraphicMesh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setLODDistance((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->moveMeshToDistance(); break;
        case 6: _t->returnLastDistance(); break;
        case 7: _t->openSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setDistanceSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->moveMeshToDistanceSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->showHideGraphicMeshSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->showHidePhisicMeshSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (toolPanel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPanel::openPhisicMesh)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (toolPanel::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPanel::openGraphicMesh)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (toolPanel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPanel::showHidePhisicMesh)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (toolPanel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPanel::showHideGraphicMesh)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (toolPanel::*)(float , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPanel::setLODDistance)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (toolPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPanel::moveMeshToDistance)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (toolPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&toolPanel::returnLastDistance)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject toolPanel::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_toolPanel.data,
      qt_meta_data_toolPanel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *toolPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *toolPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_toolPanel.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int toolPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void toolPanel::openPhisicMesh(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void toolPanel::openGraphicMesh(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void toolPanel::showHidePhisicMesh(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void toolPanel::showHideGraphicMesh(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void toolPanel::setLODDistance(float _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void toolPanel::moveMeshToDistance()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void toolPanel::returnLastDistance()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
