#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
    S = new QTcpServer(this);

    if(!S->listen(QHostAddress::Any, 8000))
        {
            qDebug() << "Server could not start";
        }
        else
        {
            qDebug() << "Server started!";
        }

    connect(S, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void server::newConnection()
{
    this->c = new connection(S->nextPendingConnection());
}
