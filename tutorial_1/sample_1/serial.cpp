#include "serial.hpp"

Serial::Serial() {

}

Serial::~Serial() {

}


void Serial::slot_init() {

	serialPort = new QSerialPort();

}

void Serial::slot_openPort(void *data) {

	struct dataStruct {
		QString portName;
		QString baudRate;
		QString dataSize;
		QString parity;
		QString stopBits;
	};

	dataStruct *ds = static_cast<dataStruct*>(data);

	if (serialPort->isOpen()) {
		serialPort->close();
	}

	serialPort->setPortName(ds->portName);
	serialPort->setBaudRate(ds->baudRate.toInt());

	if (ds->dataSize == "5") {
		serialPort->setDataBits(QSerialPort::Data5);
	}
	else if (ds->dataSize == "6") {
		serialPort->setDataBits(QSerialPort::Data6);
	}
	else if (ds->dataSize == "7") {
		serialPort->setDataBits(QSerialPort::Data7);
	}
	else if (ds->dataSize == "8") {
		serialPort->setDataBits(QSerialPort::Data8);
	}

	if (ds->parity == "None") {
		serialPort->setParity(QSerialPort::NoParity);
	}
	else if (ds->parity == "Even") {
		serialPort->setParity(QSerialPort::EvenParity);
	}
	else if (ds->parity == "Odd") {
		serialPort->setParity(QSerialPort::OddParity);
	}

	if (ds->stopBits == "1") {
		serialPort->setStopBits(QSerialPort::OneStop);
	}
	else if (ds->stopBits == "1.5") {
		serialPort->setStopBits(QSerialPort::OneAndHalfStop);
	}
	else if (ds->stopBits == "2") {
		serialPort->setStopBits(QSerialPort::TwoStop);
	}

	if (serialPort->isOpen()) {
		serialPort->close();
	}

	serialPort->open(QIODevice::ReadWrite);

	connect(serialPort, SIGNAL(readyRead()), this, SLOT(slot_receiveString()));

}

void Serial::slot_closePort() {

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

	if (serialPort->isOpen()) {

		serialPort->write(data.toUtf8());

		serialPort->waitForBytesWritten();

	}

}

void Serial::slot_receiveString() {

	QByteArray bytes = serialPort->readAll();

	emit sig_receiveString(QString::fromUtf8(bytes));
	
}


