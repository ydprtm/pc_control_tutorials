#ifndef __SERIAL_HPP__
#define __SERIAL_HPP__

#include <QObject>
#include <QSerialPort>

class Serial : public QObject 
{

	Q_OBJECT

public:

	Serial();

	~Serial();

private:
	
	QSerialPort *serialPort;

	struct portSettings{
		int comPort{ 1 };
	};

	portSettings *settings;

public slots:

	void slot_getSettings();

signals:

	void sig_updateSettings(void*);

};

#endif //!__SERIAL_HPP__