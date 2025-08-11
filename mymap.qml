import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.15
import QtPositioning 5.6
import QtQuick.Controls 2.15

Rectangle {
    id: main
    width: parent.width
    height: parent.height
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.useragent"
            value: "Qt OSM application"
        }
        PluginParameter {
            name: "osm.mapping.cache.directory" //"osm.mapping.cache.directory"
            value: "/home/ngubar/Projects/ShowMap/debug/map"
        }

        PluginParameter {
            name: "osm.mapping.providersrepository.address"
            value: "https://github.com/NatalyaGu/qt-osm-map-providers.github.io"
        }
        PluginParameter {
            name: "osm.mapping.highdpi_tiles"
            value: true
        }
        PluginParameter {
            name: "osm.mapping.offline.directory"
            value: "/home/ngubar/Projects/ShowMap/debug/map"
        }
    }

    Map {
        id: mapView
        objectName: "mapView"
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(center_latitude, center_longitude)
        zoomLevel: zoomValue
        copyrightsVisible: false
        property double center_latitude: center_latitude
        property double center_longitude: center_longitude
        property int zoom: zoomValue

        onZoomLevelChanged: {
            zoom = zoomLevel
            qmlReceiver.zoomLevelChanged(mapView.zoomLevel)
        }

        MouseArea {
            id: mapViewMouseArea
            anchors.fill: parent
            propagateComposedEvents: true
            hoverEnabled: true

            onMouseXChanged: {
                qmlReceiver.mouseMoved(
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).latitude,
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).longitude)
            }
            onMouseYChanged: {
                qmlReceiver.mouseMoved(
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).latitude,
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).longitude)
            }
        }

        function getMousePosition_lat() {
            return mapView.toCoordinate(Qt.point(
                                            mapViewMouseArea.mouseX,
                                            mapViewMouseArea.mouseY)).latitude
        }
        function getMousePosition_lon() {
            return mapView.toCoordinate(Qt.point(
                                            mapViewMouseArea.mouseX,
                                            mapViewMouseArea.mouseY)).longitude
        }

        onCenterChanged: {
            qmlReceiver.centerChanged(mapView.center.latitude,
                                      mapView.center.longitude)
        }

        Instantiator {
            model: markerModel
            delegate: MapItemGroup {
                id: delegateGroup
                objectName: "delegateGroup"

                MapQuickItem {
                    id: marker
                    anchorPoint.x: image.width / 2
                    anchorPoint.y: image.height / 2
                    coordinate: QtPositioning.coordinate(latitudeValue,
                                                         longitudeValue)
                    z: 1
                    // begin configuration
                    property var position: QtPositioning.coordinate(
                                               latitudeValue, longitudeValue)
                    property var nextposition: QtPositioning.coordinate(
                                                   nextLatitudeValue,
                                                   nextLongitudeValue)
                    //                    function markerLat() {
                    //                        return model.getMarkerLatitude(marker.id_cop)
                    //                    }
                    onPositionChanged: restart()
                    onNextpositionChanged: restart()
                    function restart() {

                        anim.stop()
                        anim.from = position
                        anim.to = nextposition
                        marker.showconnect = false
                        anim.start()
                    }
                    CoordinateAnimation {
                        id: anim
                        target: item
                        duration: 60 * 1000
                        property: "coordinate"
                    }

                    // end of configuration
                    property string identifier: identifierValue
                    property string name: nameValue
                    property string icon: iconValue
                    property string latitude: latitudeValue
                    property string longitude: longitudeValue
                    property string type: typeValue
                    property string radius: radiusValue
                    property bool showcircle: false
                    property string id_cop: copterIdValue
                    property bool showconnect: false
                    property string cop_latitude: copterLatValue
                    property string cop_longitude: copterLonValue

                    sourceItem: Image {
                        id: image
                        source: marker.icon
                    }

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        drag.target: parent
                        acceptedButtons: Qt.LeftButton | Qt.RightButton

                        onClicked: {
                            if (mouse.button === Qt.RightButton)
                                contextMenu.popup()
                            else {
                                qmlReceiver.markerClicked(
                                            marker.identifier, marker.name,
                                            marker.coordinate.latitude.toString(
                                                ),
                                            marker.coordinate.longitude.toString(
                                                ))
                            }
                        }
                        onEntered: {
                            ToolTip.timeout = 2000
                            ToolTip.visible = true
                            ToolTip.text = qsTr("%1: %2, %3").arg(
                                        marker.name).arg(
                                        marker.coordinate.latitude).arg(
                                        marker.coordinate.longitude)
                        }

                        Menu {
                            id: contextMenu
                            MenuItem {
                                text: "Показать зону действия"
                                visible: {
                                    typeValue === 0 ? true : false
                                }
                                onTriggered: {
                                    marker.showcircle = !marker.showcircle
                                }
                            }
                            MenuItem {
                                text: "Показать связь с беспилотником"
                                visible: {
                                    (typeValue === 2
                                     && marker.id_cop !== "-1") ? true : false
                                }

                                onTriggered: {
                                    //marker.showcircle = !marker.showcircle
                                    marker.showconnect = !marker.showconnect
                                    newLine()
                                }
                            }
                            MenuItem {
                                text: "Удалить"
                                onTriggered: {
                                    qmlReceiver.markerDelete(marker.identifier)
                                }
                            }
                        }

                        onPositionChanged: {
                            if (typeValue === 0)
                                circle.center = QtPositioning.coordinate(
                                            marker.coordinate.latitude,
                                            marker.coordinate.longitude)

                            if (typeValue === 2) {
                                qmlReceiver.markerClicked(
                                            marker.identifier, marker.name,
                                            marker.coordinate.latitude.toString(
                                                ),
                                            marker.coordinate.longitude.toString(
                                                ))

                                var path = line.path
                                path[0].latitude = marker.coordinate.latitude
                                path[0].longitude = marker.coordinate.longitude
                                line.path = path
                            }
                        }
                        onReleased: {

                            if (typeValue === 1)
                                qmlReceiver.changedCopPosition(
                                            marker.identifier,
                                            marker.coordinate.latitude,
                                            marker.coordinate.longitude)
                        }
                    }
                }
                function newLine() {
                    var path = line.path
                    path[1].latitude = copterLatValue
                    path[1].longitude = copterLonValue
                    line.path = path
                }

                MapCircle {
                    id: circle

                    center: QtPositioning.coordinate(latitudeValue,
                                                     longitudeValue)
                    radius: radiusValue * 1000
                    color: "yellow"
                    border.color: "yellow"
                    opacity: 0.4
                    z: 0
                    visible: marker.showcircle
                }
                function getCopLat() {
                    var sourceIndex = markerModel.index(marker.id_cop, 0)
                    return markerModel.data(sourceIndex, 265)
                }
                function getCopLon() {
                    var sourceIndex = markerModel.index(marker.id_cop, 0)
                    return markerModel.data(sourceIndex, 266)
                }

                MapPolyline {
                    id: line
                    line.width: 1
                    line.color: 'blue'
                    path: [{
                            "latitude": latitudeValue,
                            "longitude": longitudeValue
                        }, {
                            "latitude": marker.cop_latitude,
                            "longitude": marker.cop_longitude //copterLatValue,
                            //copterLonValue //getCopLon()
                        }]
                    visible: marker.showconnect
                }
            }

            onObjectAdded: mapView.addMapItemGroup(object)
            onObjectRemoved: mapView.removeMapItemGroup(object)
        }
    }
}
