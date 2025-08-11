/****************************************************************************
** Meta object code from reading C++ file 'addobjectform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../newfolder/showmap/addobjectform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addobjectform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddObjectForm_t {
    QByteArrayData data[23];
    char stringdata0[386];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddObjectForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddObjectForm_t qt_meta_stringdata_AddObjectForm = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AddObjectForm"
QT_MOC_LITERAL(1, 14, 15), // "addStationToMap"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "latitude"
QT_MOC_LITERAL(4, 40, 9), // "longitude"
QT_MOC_LITERAL(5, 50, 6), // "radius"
QT_MOC_LITERAL(6, 57, 12), // "statusactive"
QT_MOC_LITERAL(7, 70, 12), // "addQuadToMap"
QT_MOC_LITERAL(8, 83, 8), // "altitude"
QT_MOC_LITERAL(9, 92, 2), // "id"
QT_MOC_LITERAL(10, 95, 14), // "addRemoteToMap"
QT_MOC_LITERAL(11, 110, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(12, 133, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(13, 155, 36), // "on_type_comboBox_currentIndex..."
QT_MOC_LITERAL(14, 192, 5), // "index"
QT_MOC_LITERAL(15, 198, 31), // "on_latitude_lineEdit_textEdited"
QT_MOC_LITERAL(16, 230, 4), // "arg1"
QT_MOC_LITERAL(17, 235, 32), // "on_longitude_lineEdit_textEdited"
QT_MOC_LITERAL(18, 268, 29), // "on_radius_lineEdit_textEdited"
QT_MOC_LITERAL(19, 298, 31), // "on_altitude_lineEdit_textEdited"
QT_MOC_LITERAL(20, 330, 22), // "on_id_checkBox_clicked"
QT_MOC_LITERAL(21, 353, 7), // "checked"
QT_MOC_LITERAL(22, 361, 24) // "on_id_checkBox_3_clicked"

    },
    "AddObjectForm\0addStationToMap\0\0latitude\0"
    "longitude\0radius\0statusactive\0"
    "addQuadToMap\0altitude\0id\0addRemoteToMap\0"
    "on_closeButton_clicked\0on_saveButton_clicked\0"
    "on_type_comboBox_currentIndexChanged\0"
    "index\0on_latitude_lineEdit_textEdited\0"
    "arg1\0on_longitude_lineEdit_textEdited\0"
    "on_radius_lineEdit_textEdited\0"
    "on_altitude_lineEdit_textEdited\0"
    "on_id_checkBox_clicked\0checked\0"
    "on_id_checkBox_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddObjectForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   74,    2, 0x06 /* Public */,
       7,    5,   83,    2, 0x06 /* Public */,
      10,    4,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    1,  105,    2, 0x08 /* Private */,
      15,    1,  108,    2, 0x08 /* Private */,
      17,    1,  111,    2, 0x08 /* Private */,
      18,    1,  114,    2, 0x08 /* Private */,
      19,    1,  117,    2, 0x08 /* Private */,
      20,    1,  120,    2, 0x08 /* Private */,
      22,    1,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Bool,    3,    4,    8,    9,    6,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Bool,    3,    4,    9,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void AddObjectForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddObjectForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addStationToMap((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->addQuadToMap((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->addRemoteToMap((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->on_closeButton_clicked(); break;
        case 4: _t->on_saveButton_clicked(); break;
        case 5: _t->on_type_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_latitude_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_longitude_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_radius_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_altitude_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_id_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_id_checkBox_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddObjectForm::*)(double , double , double , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddObjectForm::addStationToMap)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddObjectForm::*)(double , double , double , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddObjectForm::addQuadToMap)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AddObjectForm::*)(double , double , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddObjectForm::addRemoteToMap)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddObjectForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AddObjectForm.data,
    qt_meta_data_AddObjectForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AddObjectForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddObjectForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddObjectForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddObjectForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AddObjectForm::addStationToMap(double _t1, double _t2, double _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddObjectForm::addQuadToMap(double _t1, double _t2, double _t3, int _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AddObjectForm::addRemoteToMap(double _t1, double _t2, int _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
