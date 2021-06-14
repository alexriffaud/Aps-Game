import Felgo 3.0
import QtQuick 2.0
import "."

Item {
    width: bg.width
    height: bg.height
    MultiResolutionImage {
        id: bg
        source: "../../assets/img/bg.png"
    }
}
