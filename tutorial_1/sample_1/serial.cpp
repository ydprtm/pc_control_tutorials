#include "serial.hpp"

Serial::Serial() {

	serialPort = new QSerialPort();

	settings = new portSettings();
}

Serial::~Serial() {

}

void Serial::slot_getCOMPorts() {

}

