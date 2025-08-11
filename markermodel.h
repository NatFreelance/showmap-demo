#ifndef MARKERMODEL_H
#define MARKERMODEL_H
#include <QAbstractListModel>
#include <QColor>
#include <QtQml/QQmlListProperty>
#include <QtPositioning/QGeoCoordinate>


class MapMarker: QObject
{
    Q_OBJECT
    Q_PROPERTY(QGeoCoordinate position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QGeoCoordinate copterposition READ copterposition WRITE setCopterposition NOTIFY copterpositionChanged)
    Q_PROPERTY(QGeoCoordinate stationposition READ stationposition WRITE setStationposition NOTIFY stationpositionChanged)
    Q_PROPERTY(double radius READ radius WRITE setRadius NOTIFY radiusChanged)

public:
    explicit MapMarker(QObject *parent = 0);
    MapMarker(const MapMarker &other);
    ~MapMarker();

    QGeoCoordinate position() const
    {
        return _coord;
    }
    void setPosition(const QGeoCoordinate &c) {
        if (_coord == c)
            return;

        _coord = c;
        emit positionChanged();
    }
    MapMarker &operator =(const MapMarker&m);
    void setId(const int &id);
    int id() const;
    void setName(const QString &name);
    QString name() const;
    void setCoord(const QGeoCoordinate &coord);
    QGeoCoordinate coord() const;
    void setNextCoord(const QGeoCoordinate &coord);
    QGeoCoordinate nextcoord() const;
    void setIcon(const QString &icon);
    QString icon_notactive() const;
    void setIcon_notactive(const QString &icon);
    QString icon() const;
    void setType(const int type);
    int type() const;
    void setRadius(const double radius);
    double radius() const;
    void setCopter(MapMarker *cop);
    void setStation (MapMarker *st);
    MapMarker* cop() const;
    QGeoCoordinate copterposition() const;
    void setCopterposition(const QGeoCoordinate &c);
    MapMarker *station() const;
    QGeoCoordinate stationposition() const;
    void setStationposition(const QGeoCoordinate &s);
    void setStatus(const bool s);
    bool status() const;

signals:
    void positionChanged();
    void copterpositionChanged();
    void stationpositionChanged();
    void radiusChanged();
private:
    int _id;
    QString _name;
    QGeoCoordinate _coord;
    QGeoCoordinate _next_coord;
    QString _icon;
    QString _icon_notactive;
    int _type; // 0 - станция, 1 - беспилотник, 2 - пульт, 3 - пеленгатор
    bool _status; //активен , неактивен
    double _radius; // км
    MapMarker * _cop; // указатель на беспилотник для пульта
    MapMarker* _station; // указатели на станцию для беспилотника
};

Q_DECLARE_METATYPE(MapMarker)

class MarkerModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum MarkerRoles
    {
//        latitudeRole = Qt::UserRole + 1,
//        longitudeRole = Qt::UserRole + 2,
//        altitudeRole = Qt::UserRole + 3,
//        identifierRole = Qt::UserRole + 4,
//        nameRole = Qt::UserRole + 5,
//        iconRole = Qt::UserRole + 6,
//        typeRole = Qt::UserRole + 7,
//        radiusRole = Qt::UserRole + 8,
//        NextLatitudeRole = Qt::UserRole + 9,
//        NextLongitudeRole = Qt::UserRole + 10,
//        IdCopterRole = Qt::UserRole+11,
//        latCopterRole = Qt::UserRole+12,
//        lonCopterRole = Qt::UserRole+13
          identifierRole = Qt::UserRole + 1,
          coordinateRole = Qt::UserRole + 2,
          nextcoordinateRole = Qt::UserRole + 3,
          nameRole = Qt::UserRole + 4,
          iconRole = Qt::UserRole + 5,
          typeRole = Qt::UserRole + 6,
          radiusRole = Qt::UserRole + 7,
          copidRole = Qt::UserRole + 8,
          copterpositionRole= Qt::UserRole+9,
          statusRole = Qt::UserRole+10,
          iconnotactiveRole = Qt::UserRole + 11
    };


    MarkerModel();
    ~MarkerModel() = default;

    void addMarker(const int &identifier, const QString& name, double lat, double lon, double alt, const QString& icon, const QString &icon2, int type, double radius, int idc, bool status);

    std::tuple<double, double> getMarkerLatLon(const int &identifier) const;
    double getMarkerLatitude(const int &identifier);
    double getMarketLongitude(const int &identifier);

    void setMarkerLatLon(const int &identifier, double lat, double lon);
    void setMarkerType(const int& identifier, int type);
    int getMarkerType(const int &identifier);
    void setStationRadius(const int &identifier, double rad);

    void setMarkerName(const int &identifier, const QString& name, bool redraw);

    void setMarkerIcon(const int &identifier, const QString& icon, bool redraw);

    void delMarker(const int &identifier);
    void moveCopter(const int &identifier, double dlat, double dlon);

    void clear();
    int size();
    void updateData();
    void redrawLine(const int &identifier, QGeoCoordinate coor);
    void redrawCurrent(const int &identifier);
    QList<MapMarker> getCopterList();
    QList<MapMarker> getStationList();
    void redrawAll();

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
    int indexOf(const int identifier) const;

private:
  //  QList<Marker> _markers;
    QList<MapMarker> _markers;

};

#endif // MARKERMODEL_H
