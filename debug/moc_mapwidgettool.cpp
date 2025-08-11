/****************************************************************************
** Meta object code from reading C++ file 'mapwidgettool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../newfolder/showmap/mapwidgettool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapwidgettool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMLReceiver_t {
    QByteArrayData data[21];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMLReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMLReceiver_t qt_meta_stringdata_QMLReceiver = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QMLReceiver"
QT_MOC_LITERAL(1, 12, 19), // "centerChangedSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "lat"
QT_MOC_LITERAL(4, 37, 3), // "lon"
QT_MOC_LITERAL(5, 41, 22), // "zoomLevelChangedSignal"
QT_MOC_LITERAL(6, 64, 6), // "zlevel"
QT_MOC_LITERAL(7, 71, 19), // "markerClickedSignal"
QT_MOC_LITERAL(8, 91, 10), // "identifier"
QT_MOC_LITERAL(9, 102, 4), // "name"
QT_MOC_LITERAL(10, 107, 18), // "markerDeleteSignal"
QT_MOC_LITERAL(11, 126, 16), // "mouseMovedSignal"
QT_MOC_LITERAL(12, 143, 24), // "changedCopPositionSignal"
QT_MOC_LITERAL(13, 168, 8), // "latitude"
QT_MOC_LITERAL(14, 177, 9), // "longitude"
QT_MOC_LITERAL(15, 187, 13), // "centerChanged"
QT_MOC_LITERAL(16, 201, 16), // "zoomLevelChanged"
QT_MOC_LITERAL(17, 218, 13), // "markerClicked"
QT_MOC_LITERAL(18, 232, 12), // "markerDelete"
QT_MOC_LITERAL(19, 245, 10), // "mouseMoved"
QT_MOC_LITERAL(20, 256, 18) // "changedCopPosition"

    },
    "QMLReceiver\0centerChangedSignal\0\0lat\0"
    "lon\0zoomLevelChangedSignal\0zlevel\0"
    "markerClickedSignal\0identifier\0name\0"
    "markerDeleteSignal\0mouseMovedSignal\0"
    "changedCopPositionSignal\0latitude\0"
    "longitude\0centerChanged\0zoomLevelChanged\0"
    "markerClicked\0markerDelete\0mouseMoved\0"
    "changedCopPosition"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMLReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,
       7,    4,   82,    2, 0x06 /* Public */,
      10,    1,   91,    2, 0x06 /* Public */,
      11,    2,   94,    2, 0x06 /* Public */,
      12,    3,   99,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      15,    2,  106,    2, 0x02 /* Public */,
      16,    1,  111,    2, 0x02 /* Public */,
      17,    4,  114,    2, 0x02 /* Public */,
      18,    1,  123,    2, 0x02 /* Public */,
      19,    2,  126,    2, 0x02 /* Public */,
      20,    3,  131,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double,    8,    9,    3,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,    8,   13,   14,

 // methods: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   13,   14,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double,    8,    9,   13,   14,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,    8,   13,   14,

       0        // eod
};

void QMLReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QMLReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->centerChangedSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->zoomLevelChangedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->markerClickedSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 3: _t->markerDeleteSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->mouseMovedSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->changedCopPositionSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->centerChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->zoomLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->markerClicked((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 9: _t->markerDelete((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 10: _t->mouseMoved((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 11: _t->changedCopPosition((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QMLReceiver::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLReceiver::centerChangedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QMLReceiver::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLReceiver::zoomLevelChangedSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QMLReceiver::*)(const int & , const QString & , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLReceiver::markerClickedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QMLReceiver::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLReceiver::markerDeleteSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QMLReceiver::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLReceiver::mouseMovedSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QMLReceiver::*)(const int & , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLReceiver::changedCopPositionSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QMLReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QMLReceiver.data,
    qt_meta_data_QMLReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QMLReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMLReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QMLReceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QMLReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QMLReceiver::centerChangedSignal(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMLReceiver::zoomLevelChangedSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMLReceiver::markerClickedSignal(const int & _t1, const QString & _t2, double _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMLReceiver::markerDeleteSignal(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QMLReceiver::mouseMovedSignal(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMLReceiver::changedCopPositionSignal(const int & _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_MapWidgetTool_t {
    QByteArrayData data[49];
    char stringdata0[641];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MapWidgetTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MapWidgetTool_t qt_meta_stringdata_MapWidgetTool = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MapWidgetTool"
QT_MOC_LITERAL(1, 14, 15), // "addStationOnMap"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "lat"
QT_MOC_LITERAL(4, 35, 3), // "lon"
QT_MOC_LITERAL(5, 39, 6), // "radius"
QT_MOC_LITERAL(6, 46, 6), // "status"
QT_MOC_LITERAL(7, 53, 12), // "addQuadOnMap"
QT_MOC_LITERAL(8, 66, 3), // "alt"
QT_MOC_LITERAL(9, 70, 2), // "id"
QT_MOC_LITERAL(10, 73, 24), // "addRemoteControllerOnMap"
QT_MOC_LITERAL(11, 98, 6), // "id_cop"
QT_MOC_LITERAL(12, 105, 9), // "delMarker"
QT_MOC_LITERAL(13, 115, 10), // "identifier"
QT_MOC_LITERAL(14, 126, 21), // "onCenterChangedByForm"
QT_MOC_LITERAL(15, 148, 4), // "zoom"
QT_MOC_LITERAL(16, 153, 10), // "closeEvent"
QT_MOC_LITERAL(17, 164, 12), // "QCloseEvent*"
QT_MOC_LITERAL(18, 177, 5), // "event"
QT_MOC_LITERAL(19, 183, 17), // "getmap_center_lat"
QT_MOC_LITERAL(20, 201, 17), // "getmap_center_lon"
QT_MOC_LITERAL(21, 219, 11), // "getmap_zoom"
QT_MOC_LITERAL(22, 231, 13), // "getCopterList"
QT_MOC_LITERAL(23, 245, 16), // "QList<MapMarker>"
QT_MOC_LITERAL(24, 262, 14), // "getStationList"
QT_MOC_LITERAL(25, 277, 10), // "redrawLine"
QT_MOC_LITERAL(26, 288, 8), // "latitude"
QT_MOC_LITERAL(27, 297, 9), // "longitude"
QT_MOC_LITERAL(28, 307, 9), // "load_path"
QT_MOC_LITERAL(29, 317, 13), // "set_load_path"
QT_MOC_LITERAL(30, 331, 4), // "path"
QT_MOC_LITERAL(31, 336, 9), // "imagePath"
QT_MOC_LITERAL(32, 346, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(33, 369, 15), // "onCenterChanged"
QT_MOC_LITERAL(34, 385, 15), // "onMarkerClicked"
QT_MOC_LITERAL(35, 401, 4), // "name"
QT_MOC_LITERAL(36, 406, 12), // "onMouseMoved"
QT_MOC_LITERAL(37, 419, 18), // "onZoomLevelChanged"
QT_MOC_LITERAL(38, 438, 1), // "z"
QT_MOC_LITERAL(39, 440, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(40, 461, 23), // "on_optionButton_clicked"
QT_MOC_LITERAL(41, 485, 25), // "on_clearAllButton_clicked"
QT_MOC_LITERAL(42, 511, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(43, 533, 14), // "moveAllCopters"
QT_MOC_LITERAL(44, 548, 21), // "on_stopButton_clicked"
QT_MOC_LITERAL(45, 570, 24), // "on_savemapButton_clicked"
QT_MOC_LITERAL(46, 595, 24), // "onNetworkRequestFinished"
QT_MOC_LITERAL(47, 620, 14), // "QNetworkReply*"
QT_MOC_LITERAL(48, 635, 5) // "reply"

    },
    "MapWidgetTool\0addStationOnMap\0\0lat\0"
    "lon\0radius\0status\0addQuadOnMap\0alt\0"
    "id\0addRemoteControllerOnMap\0id_cop\0"
    "delMarker\0identifier\0onCenterChangedByForm\0"
    "zoom\0closeEvent\0QCloseEvent*\0event\0"
    "getmap_center_lat\0getmap_center_lon\0"
    "getmap_zoom\0getCopterList\0QList<MapMarker>\0"
    "getStationList\0redrawLine\0latitude\0"
    "longitude\0load_path\0set_load_path\0"
    "path\0imagePath\0on_closeButton_clicked\0"
    "onCenterChanged\0onMarkerClicked\0name\0"
    "onMouseMoved\0onZoomLevelChanged\0z\0"
    "on_addButton_clicked\0on_optionButton_clicked\0"
    "on_clearAllButton_clicked\0"
    "on_playButton_clicked\0moveAllCopters\0"
    "on_stopButton_clicked\0on_savemapButton_clicked\0"
    "onNetworkRequestFinished\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MapWidgetTool[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,  154,    2, 0x0a /* Public */,
       7,    5,  163,    2, 0x0a /* Public */,
      10,    4,  174,    2, 0x0a /* Public */,
      12,    1,  183,    2, 0x0a /* Public */,
      14,    3,  186,    2, 0x0a /* Public */,
      16,    1,  193,    2, 0x0a /* Public */,
      19,    0,  196,    2, 0x0a /* Public */,
      20,    0,  197,    2, 0x0a /* Public */,
      21,    0,  198,    2, 0x0a /* Public */,
      22,    0,  199,    2, 0x0a /* Public */,
      24,    0,  200,    2, 0x0a /* Public */,
      25,    3,  201,    2, 0x0a /* Public */,
      28,    0,  208,    2, 0x0a /* Public */,
      29,    1,  209,    2, 0x0a /* Public */,
      31,    0,  212,    2, 0x0a /* Public */,
      32,    0,  213,    2, 0x08 /* Private */,
      33,    2,  214,    2, 0x08 /* Private */,
      34,    4,  219,    2, 0x08 /* Private */,
      36,    2,  228,    2, 0x08 /* Private */,
      37,    1,  233,    2, 0x08 /* Private */,
      39,    0,  236,    2, 0x08 /* Private */,
      40,    0,  237,    2, 0x08 /* Private */,
      41,    0,  238,    2, 0x08 /* Private */,
      42,    0,  239,    2, 0x08 /* Private */,
      43,    0,  240,    2, 0x08 /* Private */,
      44,    0,  241,    2, 0x08 /* Private */,
      45,    0,  242,    2, 0x08 /* Private */,
      46,    1,  243,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Bool,    3,    4,    8,    9,    6,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Bool,    3,    4,   11,    6,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int,    3,    4,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Int,
    0x80000000 | 23,
    0x80000000 | 23,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,   13,   26,   27,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double,   13,   35,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 47,   48,

       0        // eod
};

void MapWidgetTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MapWidgetTool *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addStationOnMap((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->addQuadOnMap((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->addRemoteControllerOnMap((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->delMarker((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onCenterChangedByForm((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 6: { double _r = _t->getmap_center_lat();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 7: { double _r = _t->getmap_center_lon();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->getmap_zoom();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { QList<MapMarker> _r = _t->getCopterList();
            if (_a[0]) *reinterpret_cast< QList<MapMarker>*>(_a[0]) = std::move(_r); }  break;
        case 10: { QList<MapMarker> _r = _t->getStationList();
            if (_a[0]) *reinterpret_cast< QList<MapMarker>*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->redrawLine((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 12: { QString _r = _t->load_path();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->set_load_path((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: { QString _r = _t->imagePath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->on_closeButton_clicked(); break;
        case 16: _t->onCenterChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 17: _t->onMarkerClicked((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 18: _t->onMouseMoved((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 19: _t->onZoomLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_addButton_clicked(); break;
        case 21: _t->on_optionButton_clicked(); break;
        case 22: _t->on_clearAllButton_clicked(); break;
        case 23: _t->on_playButton_clicked(); break;
        case 24: _t->moveAllCopters(); break;
        case 25: _t->on_stopButton_clicked(); break;
        case 26: _t->on_savemapButton_clicked(); break;
        case 27: _t->onNetworkRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MapWidgetTool::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MapWidgetTool.data,
    qt_meta_data_MapWidgetTool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MapWidgetTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MapWidgetTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MapWidgetTool.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MapWidgetTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
