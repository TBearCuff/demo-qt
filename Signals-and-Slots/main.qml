import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Slider {
        id: slider
        x: 155
        y: 138
        stepSize: 1
        to: 100
        value: 50
    }

    Label {
        id: label
        x: 361
        y: 143
        width: 166
        height: 31
        color: "#75507b"
        text: slider.value
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
