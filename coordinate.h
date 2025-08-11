#ifndef COORDINATE_H
#define COORDINATE_H

#include <QSharedDataPointer>
#include <QMetaType>

//class CoordinateData;

//class Coordinate
//{
//    public:
//    Coordinate();
//    Coordinate (Coordinate &o);
//    Coordinate (double lat, double lon, double alt);
//    ~Coordinate();
//    Coordinate &operator=(Coordinate &);

//    double latitude();
//    double longitude();
//    double altitude();
//    void setCoords(double lat, double lon, double alt);
//    void setLat(double l);
//    void setLon(double l);
//    void setAlt(double l);

//    private:
//    double _latitude;
//    double _longitude;
//    double _altitude;
//};
//Q_DECLARE_METATYPE(Coordinate)

//class  Coordinate
//{
//public:

//    Coordinate();
//    Coordinate(const Coordinate &);
//    Coordinate(double lat, double lon, double alt);
//    Coordinate &operator=(const Coordinate &);
//    ~Coordinate();

////    double getLat();
////    double getLon();
////    double getAlt();
//    double latitude();
//    double longitude();
//    double altitude();
//    void setCoords(double lat, double lon, double alt);
//    void setLat(double l);
//    void setLon(double l);
//    void setAlt(double l);

//private:
//   // QSharedDataPointer<CoordinateData> data;
//    double _latitude;
//    double _longitude;
//    double _altitude;
//};
//Q_DECLARE_METATYPE(Coordinate)

struct Coords {
    double lat;
    double lon;
    double alt;
};
Q_DECLARE_METATYPE(Coords)
#endif // COORDINATE_H
