import QtQuick
import Zuppi

Flickable {
	width: parent.width
	contentWidth: contentItem.childrenRect.width
	contentHeight: contentItem.childrenRect.height
	clip: true
}