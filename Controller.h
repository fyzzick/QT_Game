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

    Q_INVOKABLE void move_left();

    Q_INVOKABLE void move_right();

    Q_INVOKABLE void apply_thrust();

public slots:
    void update_state();

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
