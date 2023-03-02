import QtQuick 2.0

Image {

    id: vectorImage

    fillMode: Image.PreserveAspectFit

    property bool vectorImageAutoResize: false


    onVectorImageAutoResizeChanged: {

        if(vectorImageAutoResize){
            sourceSize.width = Qt.binding(function() { return width });
            sourceSize.height = Qt.binding(function() { return height });
        }else{
            sourceSize.width = width;
            sourceSize.height = height;
        }

//        printState();
    }

    function resize(){

        // Only apply new size when they have to be increased

        if(width > sourceSize.width){
            sourceSize.width = width;
        }

        if(height > sourceSize.height){
            sourceSize.height = height;
        }

//        printState()
    }

    function printState(){
        console.log("VectorImage: [imageSource=" + source + ",sourceSize.width=" + sourceSize.width + ",sourceSize.height=" + sourceSize.height + ",width=" + width + ",height=" + height + ",vectorImageAutoRsize=" + vectorImageAutoResize + "]")
    }

}

