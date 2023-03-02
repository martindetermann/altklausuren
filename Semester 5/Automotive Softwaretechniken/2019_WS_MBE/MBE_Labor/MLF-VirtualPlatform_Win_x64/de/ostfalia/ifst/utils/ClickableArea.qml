import QtQuick 2.0

MouseArea {

    id: clickableArea

    property real widthRelative
    property real heightRelative

    property real xRelative
    property real yRelative

    property alias clickableAreaShowBorder: rectangle.visible
    property bool clickableAreaDebugOutputEnabled: false

    signal clickableAreaClicked(var clickableArea)

    Rectangle {

        id: rectangle

        visible: false
        anchors.fill: parent

        color: "transparent"
        border.color: "black"
        border.width: 1

    }

    function updatePositionAndSize(mirrored){

        width = parent.width * widthRelative;
        height = parent.height * heightRelative;

        if(mirrored){
            x = clickableArea.parent.width * (1.0 - xRelative) - (width/2.0);
        }else{
            x = (clickableArea.parent.width * xRelative) - (width/2.0);
        }

        y = (parent.height * yRelative) - (height/2.0);

    }

    onClicked: {

        clickableAreaClicked(clickableArea)

        if(clickableAreaDebugOutputEnabled){

            var absoluteX = mouse.x;
            var absoluteY = mouse.y;

            var parentAbsoluteX = mapToItem(parent, 0, 0).x + mouse.x;
            var parentAbsoluteY = mapToItem(parent, 0, 0).y + mouse.y;

            var relativeX = absoluteX / width;
            var relativeY = absoluteY / height;

            var parentRelativeX = parentAbsoluteX / parent.width;
            var parentRelativeY = parentAbsoluteY / parent.height;


            console.log("MouseClickDebugArea:");
            console.log("Item itself:")
            console.log("  Absolute: x=" + absoluteX + " y=" + absoluteY)
            console.log("  Relative: x=" + relativeX + " y=" + relativeY)
            console.log("Parent item:")
            console.log("  Absolute: x=" + parentAbsoluteX + " y=" + parentAbsoluteY)
            console.log("  Relative: x=" + parentRelativeX + " y=" + parentRelativeY)

        }

    }

}
