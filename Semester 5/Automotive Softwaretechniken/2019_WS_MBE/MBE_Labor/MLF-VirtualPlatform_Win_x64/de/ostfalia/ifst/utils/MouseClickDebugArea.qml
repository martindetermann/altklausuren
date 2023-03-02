import QtQuick 2.0

MouseArea {

    id: mouseClickDebugArea

    anchors.fill: parent

    onClicked: {

        var xAbsolute = mouse.x;
        var yAbsolute = mouse.y;

        var xRelative = xAbsolute / width;
        var yRelative = yAbsolute / height;


        console.log("MouseClickDebugArea:");
        console.log("  Absolute: x=" + xAbsolute + " y=" + yAbsolute)
        console.log("  Relative: x=" + xRelative + " y=" + yRelative)


    }

}
