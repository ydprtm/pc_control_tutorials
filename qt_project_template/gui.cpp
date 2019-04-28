#include "gui.hpp"

gui::gui(QWidget *parent)
	: QMainWindow(parent)
{

	setMinimumSize(QSize(640, 480));

	createWidgets();
	createActions();
	createMenus();
	createLayouts();

	return;
	
}

gui::~gui() {

}

void gui::createActions() {

	quitAction = new QAction(tr("&Quit"), this);
	quitAction->setShortcut(QKeySequence::Quit);
	connect(quitAction, SIGNAL(triggered()), this, SLOT(slot_quit()));

}

void gui::createMenus() {
	
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(quitAction);

}

void gui::createWidgets() {

	baseFrame = new QFrame();
	baseFrame->setMinimumSize(QSize(640, 440));
	baseFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
}

void gui::createLayouts() {
	
	baseLayout = new QHBoxLayout();
	baseLayout->setMargin(0);
	
	baseFrame->setLayout(baseLayout);

	setCentralWidget(baseFrame);

}

void gui::slot_quit() {

	emit sig_quit();

	return;
}