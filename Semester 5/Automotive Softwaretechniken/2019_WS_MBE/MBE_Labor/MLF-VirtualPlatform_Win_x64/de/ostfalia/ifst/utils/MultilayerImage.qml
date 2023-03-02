import QtQuick 2.0

Item {

    id: multilayerImage

    property bool multilayerImageAutoResize: true
    property list<VectorImage> multilayerImageLayerList

    function addLayer( imageUrl){

        var vectorImageComponent = Qt.createComponent("VectorImage.qml");

        var newImageLayer = vectorImageComponent.createObject(multilayerImage);

        newImageLayer.source = imageUrl;
        newImageLayer.anchors.fill = Qt.binding(function() { return multilayerImage });
        newImageLayer.vectorImageAutoResize = Qt.binding(function() { return multilayerImageAutoResize });

        multilayerImageLayerList.push(newImageLayer);

        return newImageLayer;
    }

    function addLayerMoveable( imageUrl ){

        var vectorImageComponent = Qt.createComponent("VectorImage.qml");

        var newImageLayer = vectorImageComponent.createObject(multilayerImage);

        newImageLayer.source = imageUrl;
        newImageLayer.width = Qt.binding(function() { return parent.width });
        newImageLayer.height = Qt.binding(function() { return parent.height });
        newImageLayer.vectorImageAutoResize = Qt.binding(function() { return multilayerImageAutoResize });

        multilayerImageLayerList.push(newImageLayer);

        return newImageLayer;
    }

    function getLayer( layerId ){
        if(layerId < multilayerImageLayerList.length()){
            return multilayerImageLayerList[layerId];
        }
    }

    function resizeAll(){

        console.log("multilayerImage resizeAll() [width=" + width + ",height=" + height + "]");
        for(var i=0;i<multilayerImageLayerList.length;i++){
            multilayerImageLayerList[i].resize();
        }

    }

//    onWidthChanged: {
//        console.log("Width changed: " + width);
//    }

//    onHeightChanged: {
//        console.log("Height changed: " + height);
//    }

}
