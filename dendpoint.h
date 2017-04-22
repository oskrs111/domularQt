#ifndef DENDPOINT_H
#define DENDPOINT_H

#include <QObject>
#include <QTcpSocket>
#include "ddevice.h"

class dendpoint : public QObject
{
    Q_OBJECT
public:
    explicit dendpoint(QObject *parent = 0);        
    QByteArray getHtml();
    void describeRequest();
    void setEndpointConnection(QTcpSocket* socket);

private:
    QList<ddevice*> l_deviceList;
    QTcpSocket* p_endpointSocket;

    void addDevice(ddevice* device);

signals:

public slots:
    void OnReadyRead();
};

#endif // DENDPOINT_H
