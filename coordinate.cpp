#include "coordinate.h"

//class CoordinateData : public QSharedData
//{
//public:


//    CoordinateData():   lat(0), lon(0), alt(0){}
//    CoordinateData(const CoordinateData &other)
//            : QSharedData(other), lat(other.lat), lon(other.lon), alt(other.alt) { }
//    ~CoordinateData() { }

//    double lat; //широта, град
//    double lon; //долгота, град
//    double alt; //высота, м

//};

//Coordinate::Coordinate() //: data(new CoordinateData)
//{

//}

//Coordinate::Coordinate(Coordinate &rhs)
//   // : data{rhs.data}
//{
//    _latitude = rhs._latitude;
//    _longitude = rhs._longitude;
//    _altitude = rhs._altitude;
//}

//Coordinate::Coordinate(double lat, double lon, double alt)// : data (new CoordinateData)
//{
////    data->lat=lat;
////    data->lon=lon;
////    data->alt=alt;

//    _latitude = lat;
//    _longitude=lon;
//    _altitude=alt;
//}

//Coordinate &Coordinate::operator=(Coordinate &rhs)
//{
////    if (this != &rhs)
////        data.operator=(rhs.data);

//    _latitude = rhs._latitude;
//    _longitude=rhs._longitude;
//    _altitude=rhs._altitude;

//    return *this;
//}

//Coordinate::~Coordinate()
//{

//}

//double Coordinate::latitude()
//{
//    //return data->lat;
//    return _latitude;
//}

//double Coordinate::longitude()
//{
//    //return data->lon;
//    return _longitude;
//}

//double Coordinate::altitude()
//{
//    //return data->alt;
//    return _altitude;
//}

//double Coordinate::getLat()
//{
//    return data->lat;
//}

//double Coordinate::getLon()
//{
//    return data->lon;
//}

//double Coordinate::getAlt()
//{
//    return data->alt;
//}

//void Coordinate::setCoords(double lat, double lon, double alt)
//{
////    data->lat = lat;
////    data->lon=lon;
////    data->alt=alt;
//    _latitude = lat;
//    _longitude=lon;
//    _altitude=alt;
//}

//void Coordinate::setLat(double l)
//{
//   // data->lat=l;
//}

//void Coordinate::setLon(double l)
//{
//   // data->lon=l;
//}

//void Coordinate::setAlt(double l)
//{
//  //  data->alt=l;
//}
