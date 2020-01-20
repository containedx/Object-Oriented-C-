#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QTextStream>


class connection : public QObject
{
    Q_OBJECT
public:
    explicit connection( QTcpSocket *socket, QObject *parent = nullptr);
    QString message;

signals:

public slots:
    void disconnected();
    void readyread();

private:
    QTcpSocket *socket;
};

#endif // CONNECTION_H
