#ifndef DATTRIBUTE_H
#define DATTRIBUTE_H

#include <QObject>
#include <QJsonObject>
#include "devent.h"

class dattribute : public QObject
{
    Q_OBJECT
public:
    explicit dattribute(QJsonObject attributeDef, QObject *parent = 0);

private:
    QString m_attributeName;
    QString m_attributeType;
    QString m_attributeValue;
    quint32 m_permitFlags;

signals:

public slots:
    void OnSetAttribute(devent* event);
};

#endif // DATTRIBUTE_H
