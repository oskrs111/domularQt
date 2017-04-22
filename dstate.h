#ifndef DSTATE_H
#define DSTATE_H

#include <QObject>
#include <QJsonArray>
#include "devent.h"

class dstate : public QObject
{
    Q_OBJECT
public:
    explicit dstate(QJsonArray statesDef, quint32 currentState,  quint32 m_permitFlags, QObject *parent = 0);

private:
    QList<QString> m_stateAlias;
    quint32 m_currentSatate;
    quint32 m_permitFlags;

signals:

public slots:
    void OnSetState(devent* event);    
};

#endif // DSTATE_H
