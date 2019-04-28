#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>

#include <QtCore>
#include <QTcpSocket>
#include <QTcpServer>

class Client : public QObject {

	Q_OBJECT

public:

	Client();

public slots:

	void slot_onConnection();
	void slot_messageWritten();

private:

	QTcpSocket* m_socket;

signals:

	void sig_quit();

};

#endif // !__MAIN_HPP__
