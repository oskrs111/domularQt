#ifndef DEVENT_H
#define DEVENT_H

#include <QObject>

class devent : public QObject
{
    Q_OBJECT
public:
    explicit devent(QObject *parent = 0);

signals:

public slots:
};

#endif // DEVENT_H
