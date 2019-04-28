#include "main.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	gui w;

	QThread *appThread = new QThread();

	App *appTasks = new App();

	appTasks->moveToThread(appThread);

	QObject::connect(appThread, SIGNAL(started()), appTasks, SLOT(slot_init()));

	QObject::connect(&w, SIGNAL(sig_quit()), &a, SLOT(quit()));
	
	appThread->start();

	w.show();

	return a.exec();
}
