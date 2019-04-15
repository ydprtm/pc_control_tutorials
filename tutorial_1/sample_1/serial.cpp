#include "serial.hpp"

Serial::Serial() {

	serialPort = new QSerialPort();

	settings = new portSettings();
}

Serial::~Serial() {

}

void Serial::slot_getSettings() {

	settings->comPort = 2;

	void *data = static_cast<void*>(settings);

	emit sig_updateSettings(data);

}
