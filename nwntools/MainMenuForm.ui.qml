import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    property alias ddsConverterButton: ddsConverterButton

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        Button {
            id: ddsConverterButton
            text: qsTr("DDS Converter")
            checkable: false
            checked: false
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }

        Button {
            id: gffButton
            text: qsTr("GFF Tool")
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }

        Item {
            id: spacer
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
