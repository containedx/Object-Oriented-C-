#include "mainwindow.h"
#include <QApplication>
#include "server.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    server server;
    QTcpSocket* socket;
    connection x(socket);


    return a.exec();
}
