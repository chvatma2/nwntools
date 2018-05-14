import QtQuick 2.10
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Material.theme: Material.Dark
    Material.accent: Material.LightBlue

    Shortcut {
        sequences: ["Esc", "Back"]
        enabled: stackView.depth > 1
        onActivated: {
            stackView.pop()
        }
    }

    header: ToolBar {
        id: toolbar
        RowLayout {
            anchors.fill: parent
            spacing: 20

            ToolButton {
                text: "Back"
                opacity: stackView.depth > 1 ? 1 : 0
                onClicked: {
                    stackView.pop();
                }
            }

            Label {
                text: "NwN Tools"
            }
        }
    }

    StackView {
        id: stackView
        anchors.margins: 10
        anchors.fill: parent
        initialItem: MainMenuForm {
            id: mainMenu
            ddsConverterButton.onClicked: {
                stackView.push("qrc:/DDSConverter.qml")
            }
        }
    }


}
