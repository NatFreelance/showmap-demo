import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.15
import QtPositioning 5.6

MapQuickItem {
    id: marker
    property double lat: obj.latitude
    property double lon: obj.longitude
    property double alt: obj.altitude
    coordinate: QtPositioning.coordinate(
                    obj.latitude,
                    obj.longitude)
    anchorPoint.x: image.width / 2
    anchorPoint.y: image.height
}
