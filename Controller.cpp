#include "Controller.h"

Controller::Controller(QObject* parent): m_x {960/2-50}, m_y{500 - 50}, x_speed{10}, min_x{0}, max_x{910}, bottom_y {500}
{
    connect(&time, &QTimer::timeout, this, &Controller::update_state);
    time.start(16);
}

void Controller::move_left()
{
    set_x(m_x - x_speed);
    if(m_x < min_x)
    {
        set_x(min_x);
    }
}

void Controller::move_right()
{
    set_x(m_x + x_speed);
    if(m_x > max_x)
    {
        set_x(max_x);
    }
}

void Controller::apply_thrust()
{
    y_speed = max_thrust;

    if(m_y < bottom_y/1.5)
    {
        y_speed = 0;
    }
}

//slot
void Controller::update_state()
{
    m_y += y_speed;
    y_speed += gravity;

    if(m_y > bottom_y)
    {
        m_y = bottom_y;
    }

    emit yChanged();
}
