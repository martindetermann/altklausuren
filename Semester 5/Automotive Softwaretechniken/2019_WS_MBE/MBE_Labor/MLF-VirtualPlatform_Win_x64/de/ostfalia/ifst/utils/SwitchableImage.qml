import QtQuick 2.0

Image {

    property url activeSource
    property url inactiveSource

    property bool printClick: false
    property bool drawBorder: false
	property alias mouseArea: mouseArea

    id: switchableImage
    
    visible: true
    anchors.fill: parent
    sourceSize.height: parent.height
    sourceSize.width: parent.height
    fillMode: Image.PreserveAspectFit
        
    MouseArea {
    
    	id: mouseArea
    	
        width: parent.width
        height: parent.height

        onClicked: {

        	if(printClick){
        		console.log("Clickposition:");
        		console.log("[px] x: " + mouseX + " y: " + mouseY);
        		console.log("[%]  x: " + (mouseX/ parent.width) + " y: " + (mouseY/ parent.height));
        	}
    	}
    	
		Rectangle {
	        width: parent.width
	    	height: parent.height
	    	color: "transparent"
	    	
	    	border.color: "black"
	    	border.width: 1
    	
    		visible: switchableImage.drawBorder
		}

    }
    
    Component.onCompleted: {
    	setActive(false);
    }

    function setActive(active){
        if(active){
            source = activeSource;
        }else{
            source = inactiveSource;
        }
    }
    
    function isActive(){
        return (source == activeSource);
    }

}
