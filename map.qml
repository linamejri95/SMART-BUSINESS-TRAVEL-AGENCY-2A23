import QtQuick 2.0
import QtLocation 5.6

Rectangle {
    Map {
    id:mapView
    anchors.fill:parent
    center:QtPositioning.coordinate (25.6585, 125.3658);
    zoomLevel:15

    }
}
