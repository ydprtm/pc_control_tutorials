#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>

#include <QtCore>
#include <QTimer>

class Delay : public QObject {

	Q_OBJECT

public:

	Delay();

	QTimer* timer;

public slots:

	void slot_timerElapsed();

signals:

	void sig_quit();

};

#endif // !__MAIN_HPP__
