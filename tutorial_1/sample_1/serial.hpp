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

	struct portOptions {
		QStringList comPorts;
		QStringList baudRates;
		QStringList packetSize;
		QStringList parity;
		QStringList stopBits;
	};
	
	struct portSettings {
		QString comPort;
		int baudRate;
		int packetSize;
		int parity;
		int stopBits;
	};

	portOptions *options;
	portSettings *settings;

public slots:

	void slot_getOptions();

	void slot_updateSettings(void*);

signals:

	void sig_updateOptions(void*);

};

#endif //!__SERIAL_HPP__