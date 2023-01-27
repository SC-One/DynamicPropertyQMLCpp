import QtQuick 2.12
import QtQuick.Window 2.12
import github.com.sc_one 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("DynamicPropertyQMLCpp")
    DynamicCpp{
        id:dynCpp
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            dynCpp.x="WWWWWWW"
            dynCpp.y=999999
            var keys = dynCpp.keys();
            for(let i = 0 ;i<keys.length ; ++i)
                console.log("Key: " , keys[i] , "\tvalue: ",dynCpp[keys[i]]);
        }
    }
}
