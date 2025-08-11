#include "mapobject.h"

MapObject::MapObject(QObject *parent)
    : QObject{parent}, status(0)
{

}

MapObject::MapObject(MapObject *o)
{
  //  coords = o->getcoords();
  //  status = o->getStatus();
   // emit addNew(coords.getLat(), coords.getLon(), coords.getAlt());
}

MapObject::~MapObject()
{

}

void MapObject::setCoords(Coordinate &c)
{
    coords = c;
}

void MapObject::setCoords(double lat, double lon, double alt)
{
    coords.setLat(lat);
    coords.setLon(lon);
    coords.setAlt(alt);
}

int MapObject::getStatus()
{
    return status;
}

Coordinate MapObject::getcoords()
{
    return coords;
}

double MapObject::getLatitude()
{
    //return coords.getLat();
}

double MapObject::getLongitude()
{
    //return coords.getLon();
}

void MapObject::addNewObj(double lat, double lon, double alt)
{
    emit addNew(lat, lon, alt);
}

