#include <QCoreApplication>
#include <QDebug>
#include "dcore.h"

#include "../_qtkJsonRpc/qtkjosnrpc.h"

int main(int argc, char *argv[])
{
    static dcore* domularCore;
    QCoreApplication a(argc, argv);

    qtkJosnRpc j(123);
    j.setMethodKey(QString("test"));
    j.setMethodParams("{\"p1\":1000, \"p2\":2000}");
    qDebug() << j.getJsonString();




    domularCore = new dcore();

    return a.exec();
}
