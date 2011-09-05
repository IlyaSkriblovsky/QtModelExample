import Qt 4.7

Rectangle {
    width: 400
    height: 500

    Rectangle {
        id: searchbox

        anchors.left: parent.left
        anchors.right: parent.right
        height: 30

        Text {
            id: searchlabel
            text: "Search:"
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 18
        }
        Rectangle {
            anchors.left: searchlabel.right
            anchors.leftMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 1
            height: parent.height

            border.color: '#c0c0c0'

            TextInput {
                id: field
                anchors.fill: parent
                anchors.margins: 5
                font.pixelSize: 18

                onTextChanged: {
                    bookModel.setFilterWildcard(text)
                    console.log(bookModel)
                    console.log(bookModel.sort)
                    console.log(bookModel.setFilterWildcard)
                }
            }
        }
    }

    ListView {
        id: list

        clip: true

        anchors.top: searchbox.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        model: bookModel

        delegate: Item {
            width: parent.width
            height: 50

            Rectangle {
                id: background
                anchors.fill: parent

                color: mouseArea.pressed ? '#ffa0c0f0' : '#00a0c0f0'
                Behavior on color { ColorAnimation { duration: 100 } }

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                }

                Image {
                    id: image
                    source: imageUrl
                    fillMode: Image.PreserveAspectFit

                    width: height

                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                }

                Text {
                    id: nameLabel

                    anchors.left: image.right
                    anchors.leftMargin: 5
                    anchors.right: parent.right

                    text: name
                    elide: Text.ElideRight

                    font.pixelSize: 20
                    font.bold: true
                    font.capitalization: Font.SmallCaps
                }

                Text {
                    anchors.left: nameLabel.left
                    anchors.top: nameLabel.bottom

                    text: bookUrl
                }
            }
        }
    }
}
