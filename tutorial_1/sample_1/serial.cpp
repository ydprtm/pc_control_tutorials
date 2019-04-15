#include "serial.hpp"

Serial::Serial() {

	serialPort = new QSerialPort();

	options = new portOptions();
	settings = new portSettings();
}

Serial::~Serial() {

}

void Serial::slot_getOptions() {

	QList<QSerialPortInfo> availablePorts  = QSerialPortInfo::availablePorts();

	for (const auto &p : availablePorts) {

		options->comPorts.append(p.portName());

	}

	for (const auto &b : QSerialPortInfo::standardBaudRates()) {
		options->baudRates.append(QVariant::fromValue(b).toString());
	}

	QMetaEnum packetSize = QMetaEnum::fromType<QSerialPort::DataBits>();
	for (int i{ 0 }; i < packetSize.keyCount(); i++) {
		options->packetSize.append(packetSize.key(i));
	}

	QMetaEnum parity = QMetaEnum::fromType<QSerialPort::Parity>();
	for (int i{ 0 }; i < parity.keyCount(); i++) {
		options->parity.append(parity.key(i));
	}

	QMetaEnum stopBits = QMetaEnum::fromType<QSerialPort::StopBits>();
	for (int i{ 0 }; i < stopBits.keyCount(); i++) {
		options->stopBits.append(stopBits.key(i));
	}

	void *data = static_cast<void*>(options);

	emit sig_updateOptions(data);

}

void Serial::slot_updateSettings(void* data) {

	settings = static_cast<portSettings*>(data);

	if (serialPort->isOpen()) {
		serialPort->close();
	}

	serialPort->setPortName(settings->comPort);

	serialPort->setStopBits(static_cast<QSerialPort::StopBits>(settings->stopBits));

	serialPort->open(QIODevice::ReadWrite);

}