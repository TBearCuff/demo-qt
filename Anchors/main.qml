import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: background.width
    height: background.height
    title: qsTr("Anchors Away!")
    Rectangle{
//        anchors.fill: parent
        Image {
//            anchors.fill: parent
            id: background
            source: "./bluebackground.png"
                Image {
                    id: buttonTop
                    source: "./bluebutton.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    width: parent.width
                    height: parent.height / 2
                    Image {
                        id: loginIcon
                        source: "./login.png"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 8
                    }
                    Text{
                        text: qsTr("Login")
                        anchors.left: parent.horizontalCenter
                        font.pixelSize: 32
                        font.bold: true
                        color: "white"
                        anchors.verticalCenter: parent.verticalCenter
                    }
            }
                Image {
                    id: buttonBottom
                    source: "./bluebutton.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: parent.height / 2
                    Image {
                        id: signOutIcon
                        source: "./signout.png"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 8
                    }
                    Text{
                        text: qsTr("Sign Out")
                        anchors.left: parent.horizontalCenter
                        font.pixelSize: 32
                        font.bold: true
                        color: "white"
                        anchors.verticalCenter: parent.verticalCenter
                    }

            }
        }
    }
}
