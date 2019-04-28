#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>

#include <QtCore>
#include <QTcpSocket>
#include <QTcpServer>

class Server : public QObject {

	Q_OBJECT

public:

	Server();

public slots:

	void slot_acceptConnection();
	void slot_readMessage();

private:

	QTcpSocket* m_connection;
	QTcpServer* m_server;
	   
signals:

	void sig_quit();

};

#endif // !__MAIN_HPP__
