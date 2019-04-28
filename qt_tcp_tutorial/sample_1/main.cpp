#include "main.hpp"

Client::Client() :
	m_socket(new QTcpSocket())
{

	connect(m_socket, SIGNAL(connected()), this, SLOT(slot_onConnection()));
	connect(m_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(slot_messageWritten()));

	m_socket->connectToHost(QHostAddress(QString("127.0.0.1")), quint16(9601));

	std::cout << "Writing message to: " << "127.0.0.1:9601" << std::endl;

}

void Client::slot_onConnection() {
	
	QString message{ "Hello World!\r\n" };
	   
	std::cout << "Message: " << message.toStdString() << std::endl;

	std::cout << "Bytes written: " << m_socket->write(message.toUtf8()) << std::endl;
	
}

void Client::slot_messageWritten() {

	emit sig_quit();

}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	Client* c = new Client();

	QObject::connect(c, SIGNAL(sig_quit()), &a, SLOT(quit()));
	   
	return a.exec();

}
