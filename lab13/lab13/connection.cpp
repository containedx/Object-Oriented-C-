#include "connection.h"

connection::connection(QTcpSocket *socket, QObject *parent) : QObject(parent)
{
    this->socket = socket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyread()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void connection::disconnected()
{
    this->socket->close();
}

void connection::readyread()
{
    QTextStream in(this->socket);
    QTextStream out(this->socket);
    out>>message;
    in<<message.toUpper();

    qDebug() << message;
}

