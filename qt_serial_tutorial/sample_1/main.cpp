#include "main.hpp"

SerialPort::SerialPort(const QString& portName) :
	m_port(new QSerialPort()) {
	
	connect(m_port, SIGNAL(bytesWritten(qint64)), this, SLOT(slot_messageWritten()));

	m_port->setPortName(portName);
	m_port->setBaudRate(115200);
	m_port->setDataBits(QSerialPort::Data8);
	m_port->setParity(QSerialPort::NoParity);
	m_port->setStopBits(QSerialPort::OneStop);

	if (!m_port->isOpen()) {
		m_port->close();
	}

	QString message{ "Hello World!\r\n" };

	m_port->open(QIODevice::ReadWrite);

	std::cout << "Message: " << message.toStdString() << std::endl;

	std::cout << "Bytes written: " << m_port->write(message.toUtf8()) << std::endl;
		
}

void SerialPort::slot_messageWritten() {
	
	m_port->close();

	emit sig_quit();

}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	SerialPort* p = new SerialPort(QString("COM4"));

	QObject::connect(p, SIGNAL(sig_quit()), &a, SLOT(quit()));
	   
	return a.exec();

}
