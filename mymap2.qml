import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.15
import QtPositioning 5.6
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls.Styles 1.4
import "/home/ngubar/Projects/ShowMap/helper.js" as Helper

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
            value: loadPath //"/home/ngubar/Projects/ShowMap/debug/map"
        }

        //        PluginParameter {
        //            name: "osm.mapping.providersrepository.address"
        //            value: "https://github.com/NatalyaGu/qt-osm-map-providers.github.io"
        //        }
        PluginParameter {
            name: "osm.mapping.highdpi_tiles"
            value: true
        }
        PluginParameter {
            name: "osm.mapping.offline.directory"
            value: loadPath //"/home/ngubar/Projects/ShowMap/debug/map"
        }
    }

    Map {
        id: mapView
        objectName: "mapView"
        anchors.fill: parent

        plugin: mapPlugin
        center: QtPositioning.coordinate(center_latitude, center_longitude)
        zoomLevel: zoomLevel
        copyrightsVisible: false
        //visibleArea: null
        //        visibleArea: region
        // visibleRegion: geo
        //        fieldOfView: 30
        //        maximumFieldOfView: 45
        //        property var geo: QtPositioning.rectangle(
        //                              QtPositioning.coordinate(59.777, 25.0992),
        //                              QtPositioning.coordinate(49.4343, 52.1771))
        //        fieldOfView: QtPositioning.rectangle(QtPositioning.coordinate(57.777,
        //                                                                      28.0992),
        //                                             QtPositioning.coordinate(50.4343,
        //                                                                      49.1771))
        gesture.flickDeceleration: 3000
        gesture.enabled: true

        //        property variant region: QtPositioning.rectangle(
        //                                     QtPositioning.coordinate(58.777, 28.0992),
        //                                     QtPositioning.coordinate(50.4343, 49.1771))
        property double center_latitude: center_latitude
        property double center_longitude: center_longitude
        property int zoom: zoomValue
        property variant top_left: nan //QtPositioning.coordinate(58.777, 28.0992)
        property variant bottom_right: nan //QtPositioning.coordinate(50.4343,  49.1771)
        //property bool followme: false
        property variant scaleLengths: [5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000, 2000000]

        function calculateScale() {
            var coord1, coord2, dist, text, f
            f = 0
            coord1 = mapView.toCoordinate(Qt.point(0, scale.y))
            coord2 = mapView.toCoordinate(
                        Qt.point(0 + scaleImage.sourceSize.width, scale.y))
            dist = Math.round(coord1.distanceTo(coord2))

            if (dist === 0) {

                // not visible
            } else {
                for (var i = 0; i < scaleLengths.length - 1; i++) {
                    if (dist < (scaleLengths[i] + scaleLengths[i + 1]) / 2) {
                        f = scaleLengths[i] / dist
                        dist = scaleLengths[i]
                        break
                    }
                }
                if (f === 0) {
                    f = dist / scaleLengths[i]
                    dist = scaleLengths[i]
                }
            }

            text = Helper.formatDistance(dist)
            scaleImage.width = (scaleImage.sourceSize.width * f) - 2
                    * scaleImageLeft.sourceSize.width
            scaleText.text = text
        }
        onCenterChanged: {
            scaleTimer.restart()
            //            if (mapView.followme)
            //                if (mapView.center !== positionSource.position.coordinate)
            //                    mapView.followme = false
            qmlReceiver.centerChanged(mapView.center.latitude,
                                      mapView.center.longitude)
            console.info("MapCenter latitude = ", mapView.center.latitude,
                         "longitude = ", mapView.center.longitude)
            console.info("LoadPath=", loadPath)
        }

        onZoomLevelChanged: {
            scaleTimer.restart()
            //            if (mapView.followme)
            //                mapView.center = positionSource.position.coordinate
            zoom = zoomLevel
            qmlReceiver.zoomLevelChanged(mapView.zoomLevel)
        }

        onWidthChanged: {
            scaleTimer.restart()
        }

        onHeightChanged: {
            scaleTimer.restart()
        }

        Keys.onPressed: {
            if (event.key === Qt.Key_Plus) {
                mapView.zoomLevel++
            } else if (event.key === Qt.Key_Minus) {
                mapView.zoomLevel--
            }
        }
        Timer {
            id: scaleTimer
            interval: 100
            running: false
            repeat: false
            onTriggered: {
                mapView.calculateScale()
            }
        }
        Item {
            id: scale
            visible: scaleText.text != "0 m"
            z: mapView.z + 3
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 20
            height: scaleText.height * 2
            width: scaleImage.width

            Image {
                id: scaleImageLeft
                source: "/home/ngubar/Projects/ShowMap/scale_end.png"
                anchors.bottom: parent.bottom
                anchors.right: scaleImage.left
            }
            Image {
                id: scaleImage
                source: "/home/ngubar/Projects/ShowMap/scale.png"
                anchors.bottom: parent.bottom
                anchors.right: scaleImageRight.left
            }
            Image {
                id: scaleImageRight
                source: "/home/ngubar/Projects/ShowMap/scale_end.png"
                anchors.bottom: parent.bottom
                anchors.right: parent.right
            }
            Label {
                id: scaleText
                color: "#004EAE"
                anchors.centerIn: parent
                text: "0 m"
            }
            Component.onCompleted: {
                mapView.calculateScale()
            }
        }

        //        PositionSource {
        //            id: positionSource
        //            active: mapView.followme

        //            onPositionChanged: {
        //                mapView.center = positionSource.position.coordinate
        //            }
        //        }
        Slider {
            id: zoomSlider
            z: mapView.z + 3
            from: mapView.minimumZoomLevel
            to: mapView.maximumZoomLevel
            anchors.margins: 10
            anchors.bottom: scale.top
            anchors.top: parent.top
            anchors.right: parent.right
            orientation: Qt.Vertical
            value: mapView.zoomLevel
            background: Rectangle {
                //                x: control.leftPadding + control.availableWidth / 2
                //                y: control.topPadding //+ control.availableHeight / 2 - height / 2
                anchors.centerIn: parent
                implicitWidth: 5
                implicitHeight: parent.availableHeight //200
                width: implicitWidth //control.availableWidth
                height: implicitHeight
                radius: 2
                color: "#46a2da" //"transparent" //"#bdbebf"

                Rectangle {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    width: parent.width
                    height: zoomSlider.visualPosition * parent.height //parent.height
                    color: "#ECECEC"
                    radius: 2
                }
            }

            onValueChanged: {
                mapView.zoomLevel = value
            }
        }
        MapRectangle {
            id: maparea
            topLeft: mapView.top_left
            bottomRight: mapView.bottom_right

            width: parent.width / 2
            height: parent.width / 2
            color: "#ECECEC"
            opacity: 0.4
            property bool hovered: true
            border {
                width: 2
                color: "steelblue"
            }
        }

        function bbox() {
            // return mapView.visibleRegion
            return mapView.visibleRegion
        }
        function btop() {
            // return mapView.visibleRegion
            return maparea.topLeft
        }
        function bbottom() {
            // return mapView.visibleRegion
            return maparea.bottomRight
        }
        function bcenter() {
            return mapView.center
        }
        function bzoom() {
            if (mapView.zoom === 0)
                return mapView.zoomLevel
            else
                return mapView.zoom
        }
        function bzoommax() {
            return mapView.maximumZoomLevel
        }
        MouseArea {
            id: mapViewMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onPressAndHold: {
                mapView.gesture.enabled = false
                var mouse_lat = mapView.toCoordinate(
                            Qt.point(mapViewMouseArea.mouseX,
                                     mapViewMouseArea.mouseY)).latitude
                var mouse_lon = mapView.toCoordinate(
                            Qt.point(mapViewMouseArea.mouseX,
                                     mapViewMouseArea.mouseY)).longitude

                //console.info("mouse_lat =", mouse_lat, " mouse_lon=", mouse_lon)
                maparea.topLeft = QtPositioning.coordinate(mouse_lat, mouse_lon)
                //                maparea.top_lat = mouse_lat
                //                maparea.top_lon = mouse_lon
                maparea.visible = true
            }
            onPositionChanged: {
                if (mouse.wasHeld) {
                    var mouse_lat = mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).latitude
                    var mouse_lon = mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).longitude

                    //                    console.info("mouse_lat2 =", mouse_lat, " mouse_lon2=",
                    //                                 mouse_lon)
                    maparea.bottomRight = QtPositioning.coordinate(mouse_lat,
                                                                   mouse_lon)
                    maparea.visible = true
                }
            }

            onReleased: {

                var mouse_lat = mapView.toCoordinate(
                            Qt.point(mapViewMouseArea.mouseX,
                                     mapViewMouseArea.mouseY)).latitude
                var mouse_lon = mapView.toCoordinate(
                            Qt.point(mapViewMouseArea.mouseX,
                                     mapViewMouseArea.mouseY)).longitude

                // console.info("mouse_lat2 =", mouse_lat, " mouse_lon2=",
                //              mouse_lon)
                maparea.bottomRight = QtPositioning.coordinate(mouse_lat,
                                                               mouse_lon)
                mapView.gesture.enabled = true
                var sh = QtPositioning.rectangle(
                            QtPositioning.coordinate(
                                maparea.topLeft.latitude,
                                maparea.topLeft.longitude),
                            QtPositioning.coordinate(mouse_lat, mouse_lon))
                mapView.visibleRegion = sh
                // console.info("sh =", sh)
                maparea.visible = false
                // savemenu.popup()
            }

            onMouseXChanged: {
                qmlReceiver.mouseMoved(
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).latitude,
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).longitude)
                //  stopMove()
            }
            function stopMove() {

                var top_point = mapView.top_left
                var bottom_point = mapView.bottom_right

                console.info("top=", top_point)
                console.info("bottom =", bottom_point)
                var mouse_lat = mapView.toCoordinate(
                            Qt.point(mapViewMouseArea.mouseX,
                                     mapViewMouseArea.mouseY)).latitude
                var mouse_lon = mapView.toCoordinate(
                            Qt.point(mapViewMouseArea.mouseX,
                                     mapViewMouseArea.mouseY)).longitude
                console.info("mouse = ", mouse_lat, mouse_lon)
                var mymouse = mapView.toCoordinate(Qt.point(
                                                       mapViewMouseArea.mouseX,
                                                       mapViewMouseArea.mouseY))
                console.info("Mymouse = ", mymouse)

                var r = maparea.contains()

                console.info("r=", r)

                if (!r)
                    maparea.color = 'yellow'
                else
                    maparea.color = 'grey'
            }

            onMouseYChanged: {
                qmlReceiver.mouseMoved(
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).latitude,
                            mapView.toCoordinate(
                                Qt.point(mapViewMouseArea.mouseX,
                                         mapViewMouseArea.mouseY)).longitude)
                // stopMove()
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

        //        onCenterChanged: {
        //            qmlReceiver.centerChanged(mapView.center.latitude,
        //                                      mapView.center.longitude)
        //        }
        //        Menu {
        //            id: savemenu
        //            MenuItem {
        //                text: "Сохранить карту на диск"
        //                visible: true
        //                onTriggered: {
        //                    saveMap()
        //                }
        //            }
        //        }
        function saveMap() {}

        Instantiator {
            model: markerModel
            delegate: MapItemGroup {
                id: delegateGroup
                objectName: "delegateGroup"

                MapQuickItem {
                    id: marker
                    anchorPoint.x: image.width / 2
                    anchorPoint.y: image.height / 2
                    coordinate: position //coordinateValue //QtPositioning.coordinate(coordinateValue)
                    z: 1
                    // begin configuration
                    property var position: coordinateValue //QtPositioning.coordinate(latitudeValue, longitudeValue)
                    property var nextposition: nextcoordinateValue //QtPositioning.coordinate(nextLatitudeValue,nextLongitudeValue)
                    property var copterposition: copterpositionValue
                    //                    function markerLat() {
                    //                        return model.getMarkerLatitude(marker.id_cop)
                    //                    }
                    onPositionChanged: restart()
                    onNextpositionChanged: restart()
                    function restart() {

                        anim.stop()
                        anim.from = position
                        anim.to = nextposition
                        // marker.showconnect = false
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
                    property string icon_notactive: iconnotactiveValue
                    property string type: typeValue
                    property var radius: radiusValue
                    property bool showcircle: false
                    property string id_cop: copterIdValue
                    property bool showconnect: false
                    property bool active: statusValue
                    //                    property string cop_latitude: copterLatValue
                    //                    property string cop_longitude: copterLonValue
                    property var cop_coordinate: copterposition
                    property var station_coordinate: stationposition
                    signal copterPositionChanged

                    sourceItem: Image {
                        id: image
                        source: marker.active ? marker.icon : marker.icon_notactive
                    }
                    onCopterpositionChanged: {
                        newLine()
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
                                enabled: marker.active
                                onTriggered: {
                                    marker.showcircle = !marker.showcircle
                                }
                            }
                            MenuItem {
                                text: marker.active ? "Не активен" : "Активен"
                                visible: {
                                    typeValue === 0 ? true : false
                                }
                                onTriggered: {
                                    marker.active = !marker.active
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
                                circle.center = marker.coordinate //QtPositioning.coordinate(marker.coordinate.latitude,marker.coordinate.longitude)

                            if (typeValue === 1) {
                                qmlReceiver.changedCopPosition(
                                            marker.identifier,
                                            marker.coordinate.latitude,
                                            marker.coordinate.longitude)
                                marker.copterPositionChanged()
                            }
                            if (typeValue === 2) {
                                qmlReceiver.markerClicked(
                                            marker.identifier, marker.name,
                                            marker.coordinate.latitude.toString(
                                                ),
                                            marker.coordinate.longitude.toString(
                                                ))

                                var path = line.path
                                path[0].latitude = marker.position.latitude
                                path[0].longitude = marker.position.longitude
                                line.path = path
                            }
                        }
                        onReleased: {

                            //                            if (typeValue === 1){
                            //                                qmlReceiver.changedCopPosition(
                            //                                            marker.identifier,
                            //                                            marker.coordinate.latitude,
                            //                                            marker.coordinate.longitude)
                            //                            marker.copterPositionChanged()
                            //                            }
                        }
                    }
                    onCopterPositionChanged: {
                        newLine()
                    }
                }
                function newLine() {
                    var path = line.path

                    //                    path[0].latitude = marker.coordinate.latitude
                    //                    path[0].longitude = marker.coordinate.longitude
                    path[1].latitude = marker.cop_coordinate.latitude //copterLatValue
                    path[1].longitude = marker.cop_coordinate.longitude //copterLonValue
                    line.path = path
                }

                MapCircle {
                    id: circle

                    center: marker.position
                    radius: marker.radius * 1000
                    color: "yellow"
                    border.color: "yellow"
                    opacity: 0.4
                    z: 0
                    visible: marker.showcircle && marker.active
                }

                //                function getCopLat() {
                //                    var sourceIndex = markerModel.index(marker.id_cop, 0)
                //                    return markerModel.data(sourceIndex, 265)
                //                }
                //                function getCopLon() {
                //                    var sourceIndex = markerModel.index(marker.id_cop, 0)
                //                    return markerModel.data(sourceIndex, 266)
                //                }
                MapPolyline {
                    id: line
                    line.width: 1
                    line.color: 'blue'
                    path: [{
                            "latitude": marker.position.latitude,
                            "longitude": marker.position.longitude
                        }, {
                            "latitude": marker.cop_coordinate.latitude,
                            "longitude": marker.cop_coordinate.longitude //cop_longitude //copterLatValue,
                        }]
                    visible: marker.showconnect
                }
            }

            onObjectAdded: mapView.addMapItemGroup(object)
            onObjectRemoved: mapView.removeMapItemGroup(object)
        }
    }
}
