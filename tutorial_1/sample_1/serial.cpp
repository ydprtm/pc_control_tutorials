#include "serial.hpp"

Serial::Serial() {

	serialPort = new QSerialPort();
	
	createActions();

}

Serial::~Serial() {

}

void Serial::createActions() {

	connect(serialPort, SIGNAL(readyRead()), this, SLOT(slot_receiveString()));

}

void Serial::slot_getCOMPorts() {

	QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

	QList<QString> COMPorts;
	for (const auto &i : availablePorts) {
		COMPorts.append(i.portName());
	}

	struct dataStruct {
		QList<QString> COMPorts;
	};

	dataStruct *data = new dataStruct();

	data->COMPorts = COMPorts;

	emit sig_updateCOMPorts(static_cast<void*>(data));

}

void Serial::slot_transmitString(const QString &data) {

	serialPort->setPortName(QString("COM3"));
	serialPort->setBaudRate(qint32(115200));
	serialPort->setDataBits(QSerialPort::Data8);
	serialPort->setParity(QSerialPort::NoParity);
	serialPort->setStopBits(QSerialPort::OneStop);

	if (serialPort->isOpen()) {
		serialPort->close();
	}

	serialPort->open(QIODevice::ReadWrite);

	serialPort->write(data.toUtf8());
	
	serialPort->waitForBytesWritten();

	serialPort->close();

}

void Serial::slot_receiveString() {

	QByteArray bytes = serialPort->readAll();

	emit sig_receiveString(QString::fromUtf8(bytes));
	
}


