#include "dendpoint.h"

dendpoint::dendpoint(QObject *parent) : QObject(parent)
{
    this->p_endpointSocket = 0;
}

QByteArray dendpoint::getHtml()
{
    return QString("<h1>No html</h1>").toUtf8();
}

void dendpoint::describeRequest()
{
    if(this->p_endpointSocket)
    {

    }
    else
    {
        qDebug() << QString("[domular-endpoint] error, call describeRequest() without connection!");
    }

}

void dendpoint::setEndpointConnection(QTcpSocket* socket)
{

}

void dendpoint::OnReadyRead()
{

}
