#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QObject>
#include "coordinate.h"

#define COL_XPOS "xpos"
#define COL_YPOS "ypos"

class Coordinate;
class MapObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Coordinate coords READ getcoords WRITE setCoords)
    Q_PROPERTY(double latitude READ getLatitude)
    Q_PROPERTY(double longitude READ getLongitude)
public:
    explicit MapObject(QObject *parent = nullptr);
    explicit MapObject(MapObject *o);
    ~MapObject();

    enum ObjStatus {
        Active =1,
        NotActive =2
    };
    Q_ENUM(ObjStatus)

    Coordinate coords;
    int status;

 public slots:
    void setCoords(Coordinate &c);
    void setCoords(double lat, double lon, double alt);
    int getStatus();
    Coordinate getcoords();
    double getLatitude();
    double getLongitude();
    void addNewObj(double lat, double lon, double alt);

signals:
    void addNew(double lat, double lon, double alt);
};

#endif // MAPOBJECT_H
