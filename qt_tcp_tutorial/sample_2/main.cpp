#include "main.hpp"

Server::Server() :
	m_connection(new QTcpSocket()),
	m_server(new QTcpServer())
{

	connect(m_server, SIGNAL(newConnection()), this, SLOT(slot_acceptConnection()));

	m_server->listen(QHostAddress(QString("127.0.0.1")), quint16(9601));

	std::cout << "Waiting for message on: " << "127.0.0.1:9601" << std::endl;
	
}

void Server::slot_acceptConnection() {

	m_connection = m_server->nextPendingConnection();

	connect(m_connection, SIGNAL(readyRead()), this, SLOT(slot_readMessage()));
	
}

void Server::slot_readMessage() {
	
	QByteArray buffer{};
	
	buffer = m_connection->readAll();

	std::cout << "Message: " << buffer.toStdString() << std::endl;

	m_server->close();

	emit sig_quit();

}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	Server* s = new Server();

	QObject::connect(s, SIGNAL(sig_quit()), &a, SLOT(quit()));
	   
	return a.exec();

}
