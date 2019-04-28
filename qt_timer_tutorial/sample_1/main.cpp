#include "main.hpp"

Delay::Delay() :
	timer(new QTimer()) {

	connect(timer, SIGNAL(timeout()), this, SLOT(slot_timerElapsed()));
	
	std::cout << "Timer Started" << std::endl;

	timer->setSingleShot(true);
	timer->start(5000);

}

void Delay::slot_timerElapsed() {

	std::cout << "Timer Elapsed" << std::endl;

	emit sig_quit();

}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	Delay* d = new Delay();

	QObject::connect(d, SIGNAL(sig_quit()), &a, SLOT(quit()));
	   
	return a.exec();

}
