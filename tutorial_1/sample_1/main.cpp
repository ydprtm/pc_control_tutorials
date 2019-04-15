#include "main.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	gui w;

	QThread *serialThread = new QThread();

	Serial *serialTasks = new Serial();

	serialTasks->moveToThread(serialThread);

	QObject::connect(serialThread, SIGNAL(started()), serialTasks, SLOT(slot_getOptions()));

	QObject::connect(serialTasks, SIGNAL(sig_updateOptions(void*)), &w, SLOT(slot_updateOptions(void*)));
	QObject::connect(&w, SIGNAL(sig_updateSettings(void*)), serialTasks, SLOT(slot_updateSettings(void*)));

	QObject::connect(&w, SIGNAL(sig_quit()), &a, SLOT(quit()));
	
	serialThread->start();

	w.show();

	return a.exec();
}
