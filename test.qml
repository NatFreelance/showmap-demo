import QtQuick 2.15
import QtQuick.Controls 2.1
import QtQuick.Window 2.15

Item {
    Text {
        id: text
        text: qsTr("Hello World!")
        font.pointSize: 9
        anchors.centerIn: parent
    }
}
