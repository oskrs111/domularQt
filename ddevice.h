#ifndef DDEVICE_H
#define DDEVICE_H

#include <QObject>
#include "dattribute.h"
#include "dstate.h"
#include "devent.h"

class ddevice : public QObject
{
    Q_OBJECT
public:
    explicit ddevice(QObject *parent = 0);

private:
    QString m_deviceAlias;
    QList<dstate> m_stateList;
    QList<dattribute> m_attributeList;

signals:
   void setState(devent* event);
   void setAttribute(devent* event);

public slots:
    void OnSetState(devent* event);
    void OnSetAttribute(devent* event);
};

#endif // DDEVICE_H
