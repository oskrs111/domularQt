#include <QCoreApplication>
#include "dcore.h"
#include "../_qtkDebugLogger/qtkDebugLogger.h"

dcore::dcore(QObject *parent) : QObject(parent)
{
    this->p_appConfig = 0;
    this->p_webserver = 0;
    this->loadConfig();
    this->initWebInterface();
    qDebug() << QString("[domular-core] domular runing!");
}

void dcore::loadConfig()
{
   this->p_appConfig = new QtKApplicationParameters(0,QString("domular"));
   if(this->p_appConfig->fileLoad(false))
   {
       this->setConfigDefaults();
       qDebug() << QString("[domular-core] domular.cfg not found!\r\nSetting default configuration.");
       QCoreApplication::quit();
   }

   if(!this->p_appConfig->loadParam(QString("app"),QString("fileLog"),0).compare("1"))
   {
      qInstallMessageHandler(debugLogger);
   }
}

void dcore::setConfigDefaults()
{
   this->p_appConfig->saveParam(QString("app"),QString("fileLog"),QString("0"));
   this->p_appConfig->saveParam(QString("network"),QString("httpPort"),QString("80"));
   this->p_appConfig->saveParam(QString("network"),QString("domularPort"),QString("7123"));
   this->p_appConfig->fileSave();
}

void dcore::initWebInterface()
{
    this->p_webserver = new QtkHttpServer((quint16)p_appConfig->loadParam(QString("network"),QString("httpPort"),0).toInt(), this);
}

void dcore::initEndpointInterface()
{
    quint16 port = p_appConfig->loadParam(QString("network"),QString("domularPort"),0).toInt();
    this->p_tcpServer = new QTcpServer(this);
    if(this->p_tcpServer->listen(QHostAddress::Any, port))
    {
        qDebug() << QString("[domular-core] domular listening endpoints at port: %1").arg(port);
    }
    else
    {
        qDebug() << QString("[domular-core] domular error, can't create tcp server!");
    }

}

void dcore::addEndpoint(QTcpSocket* socket)
{
    dendpoint* e = new dendpoint(this);
    e->setEndpointConnection(socket);
    e->describeRequest();
    this->l_endopoints.append(e);
    qDebug() << QString("[domular-core] new endpoint connection...");
}

void dcore::OnNewConnection()
{
    QTcpSocket* s = 0;
    while(s = this->p_tcpServer->nextPendingConnection())
    {
        this->addEndpoint(s);
    }
}
