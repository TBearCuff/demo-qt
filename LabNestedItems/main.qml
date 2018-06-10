import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 480
    height: 480
    title: qsTr("Nested Items")

    Rectangle{
        id:layer0
        anchors.fill: parent
        color: "gray"
        Rectangle{
            id:layer1top
            color: "lightblue"
            x:layer0.x + 0.125 * layer0.width
            y:layer0.y + 0.125 * layer0.height
            height: layer0.height * 0.75
            width: layer0.width * 0.75
            z:1
            Rectangle{
                id:layer2top
                color: "white"
                x:layer0.x + 0.125 * layer0.width
                y:layer0.y + 0.125 * layer0.height
                height: layer0.height * 0.125
                width: layer0.width * 0.125
                z:2

            }
            Rectangle{
                id:layer2bottom
                color: "green"
                x:0
                y:0.5 * layer1top.height
                height: layer1top.height / 2
                width: layer1top.width
                z:2
                Rectangle{
                    id:layer3bottom
                    color: "blue"
                    x:layer2bottom.width / 3
                    y:layer2bottom.height /3
                    height: layer2bottom.height / 3
                    width: layer2bottom.width / 2
                    z:2

                }
            }
        }
    }
}
