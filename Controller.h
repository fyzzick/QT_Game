#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller: public QObject
{
    Q_OBJECT

    Q_PROPERTY(double x READ get_x WRITE set_x NOTIFY xChanged)
    Q_PROPERTY(double y READ get_y WRITE set_y NOTIFY yChanged)

    double get_x()
    {
        return m_x;
    }

    double get_y()
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

signals:
    void xChanged();
    void yChanged();

private:
    double m_x;
    double m_y;
    double x_speed;

public:
    Controller();
};

#endif // CONTROLLER_H
