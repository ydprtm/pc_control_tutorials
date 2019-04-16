#include "serial.hpp"

Serial::Serial() {

}

Serial::~Serial() {

}


void Serial::slot_start() {

	serialPort = new QSerialPort();

	serialPort->setPortName(QString("COM4"));
	serialPort->setBaudRate(qint32(115200));
	serialPort->setDataBits(QSerialPort::Data8);
	serialPort->setParity(QSerialPort::NoParity);
	serialPort->setStopBits(QSerialPort::OneStop);

	if (serialPort->isOpen()) {
		serialPort->close();
	}

	serialPort->open(QIODevice::ReadWrite);

	if (!serialPort->isOpen()) {
		emit sig_receiveString(QString("Error"));
	}

	connect(serialPort, SIGNAL(readyRead()), this, SLOT(slot_receiveString()));

}

void Serial::slot_stop() {

	if (serialPort->isOpen()) {
		serialPort->close();
	}

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

	serialPort->write(data.toUtf8());
	
	serialPort->waitForBytesWritten();

}

void Serial::slot_receiveString() {

	QByteArray bytes = serialPort->readAll();

	emit sig_receiveString(QString::fromUtf8(bytes));
	
}


