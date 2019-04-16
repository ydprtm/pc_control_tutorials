#include "main.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	gui w;

	QThread *serialThread = new QThread();

	Serial *serialTasks = new Serial();

	serialTasks->moveToThread(serialThread);

	QObject::connect(serialThread, SIGNAL(started()), serialTasks, SLOT(slot_init()));
	QObject::connect(serialThread, SIGNAL(started()), serialTasks, SLOT(slot_getCOMPorts()));

	QObject::connect(serialTasks, SIGNAL(sig_updateCOMPorts(void*)), &w, SLOT(slot_updateCOMPorts(void*)));

	QObject::connect(&w, SIGNAL(sig_openPort(void*)), serialTasks, SLOT(slot_openPort(void*)));

	QObject::connect(&w, SIGNAL(sig_transmitString(const QString&)), serialTasks, SLOT(slot_transmitString(const QString&)));
	QObject::connect(serialTasks, SIGNAL(sig_receiveString(const QString&)), &w, SLOT(slot_receiveString(const QString&)));

	QObject::connect(&w, SIGNAL(sig_quit()), serialTasks, SLOT(slot_closePort()));
	QObject::connect(&w, SIGNAL(sig_quit()), &a, SLOT(quit()));
	
	serialThread->start();

	w.show();

	return a.exec();
}
