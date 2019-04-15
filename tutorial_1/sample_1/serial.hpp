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

	struct portSettings {
		QStringList availablePorts;
	};

	portSettings *settings;

public slots:

	void slot_getCOMPorts();

signals:

	void sig_updateCOMPorts(void*);

};

#endif //!__SERIAL_HPP__