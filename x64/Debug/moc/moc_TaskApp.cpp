/****************************************************************************
** Meta object code from reading C++ file 'TaskApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TaskApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TaskApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TaskApp_t {
    QByteArrayData data[10];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TaskApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TaskApp_t qt_meta_stringdata_TaskApp = {
    {
QT_MOC_LITERAL(0, 0, 7), // "TaskApp"
QT_MOC_LITERAL(1, 8, 10), // "AddNewTask"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 20), // "AddFinishedTaskToLog"
QT_MOC_LITERAL(4, 41, 7), // "QTimer*"
QT_MOC_LITERAL(5, 49, 5), // "timer"
QT_MOC_LITERAL(6, 55, 17), // "DeleteTaskFromLog"
QT_MOC_LITERAL(7, 73, 7), // "QFrame*"
QT_MOC_LITERAL(8, 81, 5), // "frame"
QT_MOC_LITERAL(9, 87, 16) // "updateTaskLabels"

    },
    "TaskApp\0AddNewTask\0\0AddFinishedTaskToLog\0"
    "QTimer*\0timer\0DeleteTaskFromLog\0QFrame*\0"
    "frame\0updateTaskLabels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TaskApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    1,   38,    2, 0x0a /* Public */,
       9,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void TaskApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TaskApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddNewTask(); break;
        case 1: _t->AddFinishedTaskToLog((*reinterpret_cast< QTimer*(*)>(_a[1]))); break;
        case 2: _t->DeleteTaskFromLog((*reinterpret_cast< QFrame*(*)>(_a[1]))); break;
        case 3: _t->updateTaskLabels(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFrame* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TaskApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TaskApp.data,
    qt_meta_data_TaskApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TaskApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TaskApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TaskApp.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TaskApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
