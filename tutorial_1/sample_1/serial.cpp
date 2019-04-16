#include "serial.hpp"

Serial::Serial() {

	serialPort = new QSerialPort();

}

Serial::~Serial() {

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

void Serial::slot_transmit(const QString &data) {

	if (serialPort->isOpen()) {
		serialPort->close();
	}

	serialPort->setPortName(QString("COM3"));
	serialPort->setBaudRate(qint32(115200));
	serialPort->setDataBits(QSerialPort::Data8);
	serialPort->setParity(QSerialPort::NoParity);
	serialPort->setStopBits(QSerialPort::OneStop);

	serialPort->open(QIODevice::ReadWrite);

	serialPort->write(data.toUtf8());
	
	serialPort->waitForBytesWritten();

	serialPort->close();

}