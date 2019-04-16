#ifndef __SERIAL_HPP__
#define __SERIAL_HPP__

#include <QMetaEnum>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QVariant>

class Serial : public QObject 
{

	Q_OBJECT

public:

	Serial();

	~Serial();

private:

	QSerialPort *serialPort;

public slots:

	void slot_init();

	void slot_openPort(void*);

	void slot_getCOMPorts();

	void slot_transmitString(const QString&);

	void slot_closePort();

private slots:

	void slot_receiveString();

signals:

	void sig_updateCOMPorts(void*);

	void sig_receiveString(const QString&);

};

#endif //!__SERIAL_HPP__