import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Item {
        width: 600; height: 300

        Image {
            id:ball
            source: "images/ball.png"
            y:200
            x:parent.width/2

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    mysequentialAnim.start()
                }
            }

            SequentialAnimation{
                id: mysequentialAnim
                NumberAnimation  {
                    target: ball
                    property: "y"
                    from: 200; to: 20
                    easing.type: "Linear"
                    duration: 1000
                }
                NumberAnimation {
                    target: ball
                    property: "y"
                    from: 20; to: 200
                    easing.type: "OutBounce"
                    duration: 1000
                }
                ParallelAnimation{
                    NumberAnimation {
                        target: ball
                        property: "x"
                        to: 500
                        easing.type: Easing.OutCubic
                        duration: 1000
                    }
                    RotationAnimation {
                        target: ball
                        property: "rotation"
                        from: 0; to: 360
                        easing.type: Easing.OutCubic
                        direction: RotationAnimation.Clockwise
                        duration: 1000
                    }

                }
                ParallelAnimation{
                    NumberAnimation {
                        target: ball
                        property: "x"
                        to: 100
                        easing.type: Easing.OutCubic
                        duration: 1000
                    }
                    RotationAnimation {
                        target: ball
                        property: "rotation"
                        from: 360; to: 0
                        easing.type: Easing.OutCubic
                        direction: RotationAnimation.Counterclockwise
                        duration: 1000
                    }

                }

            }

        }
    }
}
