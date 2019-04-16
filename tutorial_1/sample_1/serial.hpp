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

	void slot_getCOMPorts();

	void slot_transmit(const QString&);

signals:

	void sig_updateCOMPorts(void*);

};

#endif //!__SERIAL_HPP__