import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    property alias selectInputFolderButton: selectInputFolderButton
    property alias selectOutputFolderButton: selectOutputFolderButton
    property alias inputFolderTextField: inputFolderTextField
    property alias outputFolderTextField: outputFolderTextField
    property alias convertButton: convertButton
    property alias outputConsole: outputConsole
    ColumnLayout {
        id: columnLayout
        opacity: 0.9
        anchors.fill: parent

        GroupBox {
            id: inputGroupBox
            Layout.fillHeight: false
            Layout.fillWidth: true
            title: qsTr("Input Folder")

            RowLayout {
                id: rowLayout
                anchors.fill: parent

                TextField {
                    id: inputFolderTextField
                    text: qsTr("")
                    font.pointSize: 9
                    Layout.fillWidth: true
                }

                Button {
                    id: selectInputFolderButton
                    text: qsTr("...")
                }
            }
        }

        GroupBox {
            id: outputGroupBox
            Layout.fillWidth: true
            title: qsTr("Output Folder")
            Layout.fillHeight: false
            RowLayout {
                id: rowLayout1
                anchors.fill: parent
                TextField {
                    id: outputFolderTextField
                    text: qsTr("")
                    font.pointSize: 9
                    Layout.fillWidth: true
                }

                Button {
                    id: selectOutputFolderButton
                    text: qsTr("...")
                }
            }
        }

        Rectangle {
            id: rectangle
            color: "#cc000000"
            radius: 1
            border.width: 1
            border.color: "#33ffffff"
            Layout.fillHeight: true
            Layout.fillWidth: true

            ScrollView {
                id: scrollView
                clip: true
                rightPadding: 5
                leftPadding: 5
                bottomPadding: 5
                topPadding: 5
                anchors.fill: parent
                Layout.fillHeight: true
                Layout.fillWidth: true

                TextArea {
                    id: outputConsole
                    text: qsTr("")
                    clip: true
                    wrapMode: Text.WordWrap
                    anchors.fill: parent
                    bottomPadding: 3
                    topPadding: 3
                    font.pointSize: 9
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }

        RowLayout {
            id: rowLayout2
            width: 100
            height: 100
            spacing: 5
            Layout.fillHeight: false
            Layout.fillWidth: true

            Item {
                id: item1
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Button {
                id: convertButton
                text: qsTr("Convert")
            }
        }
    }
}
