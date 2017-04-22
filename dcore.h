#ifndef DCORE_H
#define DCORE_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "domular.h"
#include "dendpoint.h"
#include "qtkHttpServer.h"
#include "qtkapplicationparameters.h"

class dcore : public QObject
{
    Q_OBJECT
public:
    explicit dcore(QObject *parent = 0);

private:
    void loadConfig();
    void setConfigDefaults();
    void initWebInterface();
    void initEndpointInterface();
    void addEndpoint(QTcpSocket* socket);
    QList<dendpoint*> l_endopoints;
    QtkHttpServer* p_webserver;
    QtKApplicationParameters* p_appConfig;
    QTcpServer* p_tcpServer;

signals:

public slots:
    void OnNewConnection();
};

#endif // DCORE_H
