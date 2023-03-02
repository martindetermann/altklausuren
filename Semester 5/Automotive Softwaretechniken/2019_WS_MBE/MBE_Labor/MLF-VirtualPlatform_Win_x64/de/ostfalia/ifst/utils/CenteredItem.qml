import QtQuick 2.0

Item {

    id: centeredItem

    property int centeredItemCenterX: 0
    property int centeredItemCenterY: 0

    x: centeredItemCenterX - (width/2)
    y: centeredItemCenterY - (height/2)

}
