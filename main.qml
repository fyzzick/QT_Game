import QtQuick

Window {
    width: 960
    height: 540
    visible: true
    title: qsTr("Game")

    Rectangle
    {
        id: move
        width: 50
        height: 50
        color: "green"

        x: control.x
        y: control.y

        focus: true

        Keys.onPressed: function(event)
        {
            if(event.key === Qt.Key_Left)
            {
                control.move_left()
            }
            if(event.key === Qt.Key_Right)
            {
               control.move_right()
            }
            if(event.key === Qt.Key_Up)
            {
                  control.move_up()
            }
            if(event.key === Qt.Key_Down)
            {
                  control.move_down()
            }
        }
    }
}
