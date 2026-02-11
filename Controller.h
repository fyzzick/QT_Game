#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>

class Controller: public QObject
{
    Q_OBJECT

    Q_PROPERTY(double x READ get_x WRITE set_x NOTIFY xChanged)
    Q_PROPERTY(double y READ get_y WRITE set_y NOTIFY yChanged)

public:
    Controller(QObject* parent = nullptr);

    double get_x() const
    {
        return m_x;
    }

    double get_y() const
    {
        return m_y;
    }

    void set_x(double value)
    {
        if(m_x != value)
        {
            m_x = value;
            emit xChanged();
        }
    }

    void set_y(double value)
    {
        if(m_y != value)
        {
            m_y = value;
            emit yChanged();
        }
    }

    Q_INVOKABLE void move_left()
    {
        set_x(m_x - x_speed);
        if(m_x < min_x)
        {
            set_x(min_x);
        }
    }

    Q_INVOKABLE void move_right()
    {
        set_x(m_x + x_speed);
        if(m_x > max_x)
        {
            set_x(max_x);
        }
    }

    Q_INVOKABLE void apply_thrust()
    {
        y_speed = max_thrust;

        if(m_y < bottom_y/1.5)
        {
            y_speed = 0;
        }
    }

public slots:
    void update_state()
    {
        m_y += y_speed;
        y_speed += gravity;

        if(m_y > bottom_y)
        {
            m_y = bottom_y;
        }

        emit yChanged();
    }

signals:
    void xChanged();
    void yChanged();

private:
    double m_x {0};
    double m_y {0};
    double x_speed {10};
    double min_x {0};
    double max_x {960};
    double bottom_y {500};

    double y_speed {0};
    double max_thrust {-15};
    double gravity {0.5};

    QTimer time;
};

#endif // CONTROLLER_H
