#include "gui.hpp"

gui::gui(QWidget *parent)
	: QMainWindow(parent)
{

	createActions();
	createMenus();
	createWidgets();	

	return;
	
}

gui::~gui() {

}

void gui::createActions() {

	quitAction = new QAction(tr("&File"), this);
	quitAction->setShortcut(QKeySequence::Quit);
	quitAction->setStatusTip(tr("Quit"));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(slot_quit()));


}
void gui::createMenus() {
	
	fileMenu = menuBar()->addMenu(tr("&Quit"));
	fileMenu->addAction(quitAction);

}

void gui::createWidgets() {

}

void gui::slot_quit() {

	emit sig_quit();

	return;
}