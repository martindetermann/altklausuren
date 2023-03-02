import QtQuick 2.0

Item {

    id: aspectRatioItem

    property int aspectRatioWidth: 1
    property int aspectRatioHeight: 1
    property real aspectRatio: (aspectRatioWidth / aspectRatioHeight)
    property alias aspectRatioItemBorder: aspectRatioItemBorderRectangle.visible

    anchors.centerIn: parent

    onAspectRatioWidthChanged: updateAspectRatio()
    onAspectRatioHeightChanged: updateAspectRatio()

    Component.onCompleted: {
        parent.onWidthChanged.connect(updateSize);
        parent.onHeightChanged.connect(updateSize);

        updateSize();
    }

    Rectangle {

        id: aspectRatioItemBorderRectangle

        anchors.fill: parent
        visible: false

        color: "transparent"
        border.width: 1
        border.color: "red"

    }

    function updateAspectRatio(){
        aspectRatio = (aspectRatioWidth / aspectRatioHeight)
    }

    function updateSize(){

        var parentAspectRatio = parent.width / parent.height;

        if(aspectRatio > parentAspectRatio){
            aspectRatioItem.width = Qt.binding(function() { return aspectRatioItem.parent.width });
            aspectRatioItem.height = Qt.binding(function() { return aspectRatioItem.parent.width / aspectRatio });
        }else{
            aspectRatioItem.height = Qt.binding(function() { return aspectRatioItem.parent.height });
            aspectRatioItem.width = Qt.binding(function() { return aspectRatioItem.parent.height * aspectRatio });
        }

    }

}
