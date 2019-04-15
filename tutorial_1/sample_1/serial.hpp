#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <QObject>

class Serial : public QObject 
{

	Q_OBJECT

public:

	Serial();

	~Serial();

	void slot_test();

private:

signals:

	void sig_test();

};

#endif //!__SERIAL_H__