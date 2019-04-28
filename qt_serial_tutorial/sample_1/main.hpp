#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>

#include <QtCore>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialPort : public QObject {

	Q_OBJECT

public:

	SerialPort(const QString& portName);

public slots:

	void slot_messageWritten();

private:

	QSerialPort* m_port;

signals:

	void sig_quit();

};

#endif // !__MAIN_HPP__
