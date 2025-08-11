#include "markermodel.h"
#include <random>

MarkerModel::MarkerModel()
{

}
void MarkerModel::addMarker(const int& identifier, const QString& name, double lat, double lon, double alt, const QString& icon, const QString& icon2, int type, double radius, int idc, bool status)
{
//    int idcop;
//    if(idc!="-1")
//       idcop = indexOf(idc);
//    else idcop=-1;

    MapMarker m;
    m.setId(identifier);
    m.setName(name);
    m.setCoord(QGeoCoordinate(lat, lon, alt));
    m.setNextCoord(QGeoCoordinate(lat, lon, alt));
    m.setIcon(icon);
    m.setIcon_notactive(icon2);
    m.setType(type);
    m.setRadius(radius);
    m.setStatus(status);

    auto l = m.coord().latitude();
    auto lo = m.coord().longitude();

    if(type==1 && idc>0)
    {
        MapMarker *k;
        for(int i=0; i<_markers.size(); i++)
        {
            k=&_markers[i];
            if(k->id()==idc)
            {
                m.setStation(k);
                break;
            }
        }
    }

    if(type == 2 && idc>0)
    {
    MapMarker *k;
    for(int i=0; i<_markers.size(); i++)
    {
        k=&_markers[i];
        if(k->id()==idc)
        {
            m.setCopter(k);
            break;
        }
    }
}
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    //_markers.append(Marker{ identifier, name, lat, lon, lat, lon, alt, icon, type, radius, idc, clat, clon});
    _markers.append(m);
    endInsertRows();
}


std::tuple<double, double> MarkerModel::getMarkerLatLon(const int& identifier) const
{
    int row = indexOf(identifier);
    if (row == -1)
        return std::make_tuple(0.f, 0.f);
    return std::make_tuple(_markers[row].coord().latitude(), _markers[row].coord().longitude());
}

double MarkerModel::getMarkerLatitude(const int &identifier)
{
    int row = indexOf(identifier);
    if (row == -1)
        return 0.0;
    return _markers[row].coord().latitude();
}

double MarkerModel::getMarketLongitude(const int &identifier)
{
    int row = indexOf(identifier);
    if (row == -1)
        return 0.0;
    return _markers[row].coord().longitude();
}
void MarkerModel::setMarkerLatLon(const int& identifier, double lat, double lon)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;
    _markers[row].setCoord(QGeoCoordinate (lat, lon));
//    _markers[row]._latitude= lat;
//    _markers[row]._longitude = lon;
}

void MarkerModel::setMarkerType(const int &identifier, int type)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;
    _markers[row].setType(type);
}

int MarkerModel::getMarkerType(const int &identifier)
{
    int row = indexOf(identifier);
    if(row == -1)
        return -1;
    return _markers[row].type();
}

void MarkerModel::setStationRadius(const int &identifier, double rad)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;
    if (_markers[row].type()==0) _markers[row].setRadius(rad);
}
void MarkerModel::setMarkerName(const int& identifier, const QString& name, bool redraw)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;
    _markers[row].setName(name);
    if(redraw)
        emit dataChanged(index(row, 0), index(row, 0));
}
void MarkerModel::setMarkerIcon(const int& identifier, const QString& icon, bool redraw)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;
    _markers[row].setIcon( icon);
    if(redraw)
        emit dataChanged(index(row, 0), index(row, 0));
}
void MarkerModel::delMarker(const int& identifier)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;

    beginRemoveRows(QModelIndex(), 0, _markers.count());
    if(_markers[row].type()==0)
    {
        for(int i=0; i < _markers.count(); ++i){
            MapMarker & data = _markers[i];

            if(data.type()==1 && data.station()->id()==_markers[row].id())
            {
                int ix = indexOf(data.id());
                beginRemoveRows(QModelIndex(), ix, ix);

                _markers.removeAt(ix);
                endRemoveRows();
            }
        }
    }
    beginRemoveRows(QModelIndex(), row, row);
    _markers.removeAt(row);
    endRemoveRows();
}

void MarkerModel::moveCopter(const int &identifier, double dlat, double dlon)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;
    if(_markers[row].type()==1)
    {
//        _markers[row]._latitude+=dlat;
//        _markers[row]._longitude+=dlon;
        QGeoCoordinate c(_markers[row].coord());
        c.setLatitude(c.latitude()+dlat);
        c.setLongitude(c.longitude()+dlon);
        _markers[row].setCoord(c);

        emit dataChanged(index(row, 0), index(row, 0));
    }
}
void MarkerModel::clear()
{
    _markers.clear();
    emit layoutChanged();
}

int MarkerModel::size()
{
    return _markers.size();
}

void MarkerModel::updateData()
{
    //qDebug() << __PRETTY_FUNCTION__;
           static std::default_random_engine e;
           static std::uniform_real_distribution<> dis(-.1, .1);
           for(int i=0; i < _markers.count(); ++i){
               MapMarker & data = _markers[i];
               QModelIndex ix = index(i);
               if(data.type()==1)
               {
//               data._latitude = data._next_latitude;
//               data._longitude = data._next_longitude;
//               data._next_latitude +=dis(e);//0.1;
//               data._next_longitude+=dis(e);
               QGeoCoordinate c = data.nextcoord();
               c.setLatitude(data.nextcoord().latitude()+dis(e));
               c.setLongitude(data.nextcoord().longitude()+dis(e));
               data.setCoord(data.nextcoord());
               data.setNextCoord(c);

               emit dataChanged(ix, ix);

               for(int y=0; y<_markers.count(); ++y)
               {
                   MapMarker &data2 = _markers[y];
                   QModelIndex iy = index(y);
                   if(data2.type()==2 && data2.cop()->id() == data.id())
                   {
//                       data2._cop_latitude = data._latitude;
//                       data2._cop_longitude = data._longitude;
                       data2.cop()->setCoord(data.coord());

                       emit dataChanged(iy, iy);
                   }
               }


               }
           }
}

void MarkerModel::redrawLine(const int &identifier, QGeoCoordinate coor)
{
    int row = indexOf(identifier);
    if(row == -1)
        return;

    for(int i=0; i<_markers.count(); i++)
    {
        MapMarker & data = _markers[i];
        QModelIndex ix = index(i);
        if(data.type()==2)
        {

            if(data.cop()->id()==identifier)
            {
                data.setCopterposition(coor); //setCoord(coor);
                emit _markers[i].copterpositionChanged();
                emit dataChanged(ix, ix);

            }
        }
    }

}
void MarkerModel::redrawCurrent(const int& identifier)
{
    int row = indexOf(identifier);
    if(row != -1)
        emit dataChanged(index(row, 0), index(row, 0));
}

QList<MapMarker> MarkerModel::getCopterList()
{
    QList<MapMarker> copters;
    for(int i=0; i < _markers.count(); ++i){
        MapMarker & data = _markers[i];
        if(data.type()==1)
        {
            copters.push_back(data);
        }

}
    return copters;
}

QList<MapMarker> MarkerModel::getStationList()
{
    QList<MapMarker> stations;
    for(int i=0; i < _markers.count(); ++i){
        MapMarker & data = _markers[i];
        if(data.type()==0)
        {
            stations.push_back(data);
        }

}
    return stations;
}
void MarkerModel::redrawAll()
{
    for(int row = 0; row < _markers.size(); ++row)
        emit dataChanged(index(row, 0), index(row, 0));
}

int MarkerModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return _markers.count();
}

QVariant MarkerModel::data(const QModelIndex& index, int role) const
{
    if(index.row() < 0 ||
       index.row() >= _markers.count())
        return QVariant();
//    if (role == MarkerModel::latitudeRole)
//        return QVariant::fromValue(_markers[index.row()]._latitude);
//    else if (role == MarkerModel::longitudeRole)
//        return QVariant::fromValue(_markers[index.row()]._longitude);
//    else if (role == MarkerModel::altitudeRole)
//        return QVariant::fromValue(_markers[index.row()]._altitude);
//    else if (role == MarkerModel::identifierRole)
//        return QVariant::fromValue(_markers[index.row()]._identifier);
//    else if (role == MarkerModel::nameRole)
//        return QVariant::fromValue(_markers[index.row()]._name);
//    else if(role == MarkerModel::iconRole)
//        return QVariant::fromValue(_markers[index.row()]._icon);
//    else if(role == MarkerModel::typeRole)
//        return QVariant::fromValue(_markers[index.row()]._type);
//    else if(role == MarkerModel::radiusRole)
//        return QVariant::fromValue(_markers[index.row()]._raduis);
//    else if(role == MarkerModel::NextLatitudeRole)
//        return QVariant::fromValue(_markers[index.row()]._next_latitude);
//    else if(role == MarkerModel::NextLongitudeRole)
//        return QVariant::fromValue(_markers[index.row()]._next_longitude);
//    else if(role == MarkerModel::IdCopterRole)
//        return QVariant::fromValue(_markers[index.row()]._id_copter);
//    else if(role == MarkerModel::latCopterRole)
//        return QVariant::fromValue(_markers[index.row()]._cop_latitude);
//    else if(role == MarkerModel::lonCopterRole)
//        return QVariant::fromValue(_markers[index.row()]._cop_longitude);

    if (role == MarkerModel::identifierRole)
        return QVariant::fromValue(_markers[index.row()].id());
    else if (role == MarkerModel::coordinateRole)
        return QVariant::fromValue(_markers[index.row()].coord());
    else if (role == MarkerModel::nextcoordinateRole)
        return QVariant::fromValue(_markers[index.row()].nextcoord());
    else if (role == MarkerModel::nameRole)
        return QVariant::fromValue(_markers[index.row()].name());
    else if(role == MarkerModel::iconRole)
        return QVariant::fromValue(_markers[index.row()].icon());
    else if(role == MarkerModel::typeRole)
        return QVariant::fromValue(_markers[index.row()].type());
    else if(role == MarkerModel::radiusRole)
        return QVariant::fromValue(_markers[index.row()].radius());
    else if(role == MarkerModel::copidRole)
    {
        if(_markers[index.row()].cop()!=NULL)
            return QVariant::fromValue(_markers[index.row()].cop()->id());
        else return QVariant::fromValue(-1);
    }
    else if(role == MarkerModel::copterpositionRole)
    {
        if(_markers[index.row()].cop()!=NULL)
            return QVariant::fromValue(_markers[index.row()].cop()->coord());
        else return QVariant::fromValue(-1);
    }
    else if(role == MarkerModel::statusRole)
        return QVariant::fromValue(_markers[index.row()].status());
    else if(role == MarkerModel::iconnotactiveRole)
        return QVariant::fromValue(_markers[index.row()].icon_notactive());
    return QVariant();
}

QHash<int, QByteArray> MarkerModel::roleNames() const
{
    QHash<int, QByteArray> roles;
//    roles[latitudeRole] = "latitudeValue";
//    roles[longitudeRole] = "longitudeValue";
//    roles[altitudeRole] = "altitudeValue";
//    roles[identifierRole] = "identifierValue";
//    roles[nameRole] = "nameValue";
//    roles[iconRole] = "iconValue";
//    roles[typeRole] ="typeValue";
//    roles[radiusRole] = "radiusValue";
//    roles[NextLatitudeRole] = "nextLatitudeValue";
//    roles[NextLongitudeRole] = "nextLongitudeValue";
//    roles[IdCopterRole] = "copterIdValue";
//    roles[latCopterRole] = "copterLatValue";
//    roles[lonCopterRole] = "copterLonValue";

    roles[identifierRole] = "identifierValue";
    roles[coordinateRole] = "coordinateValue";
    roles[nextcoordinateRole] = "nextcoordinateValue";
    roles[nameRole] = "nameValue";
    roles[iconRole] = "iconValue";
    roles[typeRole] = "typeValue";
    roles[radiusRole] = "radiusValue";
    roles[copidRole] = "copterIdValue";
    roles[copterpositionRole] = "copterpositionValue";
    roles[statusRole] = "statusValue";
    roles[iconnotactiveRole] = "iconnotactiveValue";

    return roles;
}
int MarkerModel::indexOf(const int identifier) const
{
    for(int i = 0; i < _markers.size(); ++i)
        if(_markers[i].id() == identifier)
            return i;
    return -1;
}


MapMarker::MapMarker(QObject *parent): QObject(parent)
{
    _cop=NULL;
    _station=NULL;
}

MapMarker::MapMarker(const MapMarker &other):         QObject(0),
    _id(other._id),
    _name(other._name),
    _coord(other._coord),
    _next_coord(other._next_coord),
    _icon(other._icon),
    _icon_notactive(other._icon_notactive),
    _type(other._type),
    _radius(other._radius),
    _cop(other._cop),
    _station(other._station),
    _status(other._status)
{

}

MapMarker::~MapMarker()
{

}

MapMarker &MapMarker::operator =(const MapMarker &m)
{
    _id=m._id;
    _name=m._name;
    _coord=m._coord;
    _next_coord=m._next_coord;
    _icon = m._icon;
    _icon_notactive = m._icon_notactive;
    _type = m._type;
    _radius = m._radius;
    _cop=m._cop;
    _station = m._station;
    _status = m._status;
    return *this;
}

void MapMarker::setId(const int &id)
{
    _id=id;
}

int MapMarker::id() const
{
    return _id;
}

void MapMarker::setName(const QString &name)
{
    _name=name;
}

QString MapMarker::name() const
{
    return _name;
}

void MapMarker::setCoord(const QGeoCoordinate &coord)
{
    _coord=coord;
}

QGeoCoordinate MapMarker::coord() const
{
    return _coord;
}

void MapMarker::setNextCoord(const QGeoCoordinate &coord)
{
_next_coord=coord;
}

QGeoCoordinate MapMarker::nextcoord() const
{
    return _next_coord;
}

void MapMarker::setIcon(const QString &icon)
{
    _icon = icon;
}

QString MapMarker::icon_notactive() const
{
    return _icon_notactive;
}

void MapMarker::setIcon_notactive(const QString &icon)
{
    _icon_notactive=icon;
}

QString MapMarker::icon() const
{
    return _icon;
}

void MapMarker::setType(const int type)
{
    _type = type;
}

int MapMarker::type() const
{
    return _type;
}

void MapMarker::setRadius(const double radius)
{
    _radius = radius;
}

double MapMarker::radius() const
{
    return _radius;
}

void MapMarker::setCopter( MapMarker *cop)
{
    _cop=cop;
}

void MapMarker::setStation(MapMarker *st)
{
    _station = st;
}

MapMarker *MapMarker::cop() const
{
    return _cop;
}

QGeoCoordinate MapMarker::copterposition() const
{
    QGeoCoordinate c;
    if(_cop)
        c = _cop->coord();
    return c;
}

void MapMarker::setCopterposition(const QGeoCoordinate &c)
{
    if(_cop) _cop->setCoord(c);

}

MapMarker *MapMarker::station() const
{
    return _station;
}

QGeoCoordinate MapMarker::stationposition() const
{
    QGeoCoordinate c;
    if(_station)
        c = _station->coord();
    return c;
}

void MapMarker::setStationposition(const QGeoCoordinate &s)
{
    if(_station) _station->setCoord(s);
}

void MapMarker::setStatus(const bool s)
{
    _status = s;
}

bool MapMarker::status() const
{
    return _status;
}
