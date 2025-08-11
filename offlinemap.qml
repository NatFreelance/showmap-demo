import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.15
import QtPositioning 5.6

Item {
    id: mapitem
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm" //"osm" // "mapboxgl", "esri", ...
        PluginParameter {
            name: "osm.useragent"
            value: "Qt OSM application"
        }
        PluginParameter {
            name: "osm.mapping.cache.directory" //"osm.mapping.cache.directory"
            value: "/home/ngubar/Projects/ShowMap/debug/map"
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
            value: "/home/ngubar/Projects/ShowMap/debug/map"
        }
    }

    PositionSource {
        id: positionSource
        active: true
        onPositionChanged: {
            map.center = position.coordinate
        }
    }
    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        //activeMapType: map.supportedMapTypes[1]
        center: QtPositioning.coordinate(55.6667, 37.4046) // Moscow region
        zoomLevel: 14

        signal addNew(double lat, double lon, double alt)

        //        MapCircle {
        //            color: "green"
        //            center: QtPositioning.coordinate(55.6667, 37.4046) // Moscow region
        //            radius: 500
        //        }
        MapQuickItem {
            id: marker
            coordinate: QtPositioning.coordinate(
                            obj.latitude,
                            obj.longitude) //QtPositioning.coordinate(55.6667, 37.4046)
            sourceItem: Image {
                id: image

                source: "/home/ngubar/Projects/ShowMap/marker.png"
            }

            anchorPoint.x: image.width / 2
            anchorPoint.y: image.height
        }

        Component {
            id: provider
            MapQuickItem {
                id: marker
                coordinate: QtPositioning.coordinate(
                                obj.latitude,
                                obj.longitude) //QtPositioning.coordinate(55.6667, 37.4046)
                sourceItem: Image {
                    id: image

                    source: "/home/ngubar/Projects/ShowMap/marker.png"
                }

                anchorPoint.x: image.width / 2
                anchorPoint.y: image.height
            }
        }

        function addNewObj(mmap, lat, lon, alt) {
            console.log(lat)
            var o = provider.createObject(mmap)
            o.center = QtPositioning.coordinate(lat, lon)
            mmap.addMapItem(o)
            return o
        }
        Connections {
            target: obj
            onAddNew: {
                var o = addNewObj(map, obj.latitude, obj.longitude, 0.0)
                console.log(m.latitude)
            }
        }

        //        MapQuickItem {
        //            id: addmarker
        //            coordinate: QtPositioning.coordinate(
        //                            obj.latitude,
        //                            obj.longitude) //QtPositioning.coordinate(55.6667, 37.4046)
        //            sourceItem: Image {
        //                id: addimage

        //                source: "/home/ngubar/Projects/ShowMap/marker.png"
        //            }

        //            anchorPoint.x: image.width / 2
        //            anchorPoint.y: image.height
        //        }

        //        Connections {
        //            target: obj
        //            onAddNew: {
        //                onAddNew()
        //            }
        //        }
        //        function onAddNew() {
        //            map.addMapItem(addmarker)
        //        }
        //        function onError(description) {}

        //        Component.onCompleted: {
        //            addNew.connect(onAddNew)
        //        }

        //        MapItemView {
        //            model: routeModel
        //            delegate: Component {
        //                MapRoute {
        //                    route: routeData
        //                    line.color: "blue"
        //                    line.width: 4
        //                }
        //            }
        //        }

        //        GeocodeModel {
        //            plugin: map.plugin
        //            query: "Moscow, Kremlin"
        //            onLocationsChanged: {
        //                if (count)
        //                    marker.coordinate = get(0).coordinate
        //            }
        //            Component.onCompleted: update()
        //        }
        //        RouteModel {
        //            id: routeModel
        //            plugin: map.plugin
        //            query: RouteQuery {
        //                id: routeQuery
        //            }
        //            Component.onCompleted: {
        //                routeQuery.addWaypoint(QtPositioning.coordinate(55.6667,
        //                                                                37.4046))
        //                routeQuery.addWaypoint(QtPositioning.coordinate(58.6667,
        //                                                                37.4046))
        //                update()
        //            }
        //        }
    }
}
