import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Game")

    Rectangle
    {
        id: move
        width: 50
        height: 50
        color: "green"

        x: 100
        y: 100

        focus: true

        Keys.onPressed: function(event)
        {
            if(event.key === Qt.Key_Left)
            {
                move.x -= 10;
            }
            if(event.key === Qt.Key_Right)
            {
                move.x += 10;
            }
            if(event.key === Qt.Key_Up)
            {
                move.y -= 10;
            }
            if(event.key === Qt.Key_Down)
            {
                move.y += 10;
            }
        }
    }
}
