import QtQuick 2.4
import QtQuick.Dialogs 1.2
import nwntools.dds 1.0

DDSConverterForm {
    inputFolderTextField.readOnly: true
    outputFolderTextField.readOnly: true
    inputFolderTextField.activeFocusOnPress: false
    outputFolderTextField.activeFocusOnPress: false
    inputFolderTextField.text: ddsHandler.inputFolder
    outputFolderTextField.text: ddsHandler.outputFolder
    outputConsole.readOnly: true



    selectInputFolderButton.onClicked: {
        inputFolderSelectDialog.open()
    }

    selectOutputFolderButton.onClicked: {
        outputFolderSelectDialog.open()
    }

    convertButton.onClicked: {
        ddsHandler.onStartConversion()
    }

    FileDialog {
        id: inputFolderSelectDialog
        selectFolder: true
        selectMultiple: false
        onAccepted: {
            ddsHandler.inputFolder = fileUrl;
        }
    }

    FileDialog {
        id: outputFolderSelectDialog
        selectFolder: true
        selectMultiple: false
        onAccepted: {
            ddsHandler.outputFolder = fileUrl;
        }
    }

    DDSHandler {
        id: ddsHandler
        onFileConverted: {
            outputConsole.append(fileName + " converted.\n")
        }
    }
}
