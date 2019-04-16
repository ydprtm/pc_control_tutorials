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
	
	leftFrame = new QFrame();
	leftFrame->setMinimumSize(QSize(510, 440));
	leftFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	rightFrame = new QFrame();
	rightFrame->setMinimumSize(QSize(110, 440));
	rightFrame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	
	transmitLabel = new QLabel();
	transmitLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	transmitLabel->setText(QString("Transmit"));

	transmitTextEdit = new QTextEdit();
	transmitTextEdit->setMinimumSize(QSize(500, 100));
	transmitTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	receiveLabel = new QLabel();
	receiveLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	receiveLabel->setText(QString("Receive"));

	receiveTextEdit = new QTextEdit();
	receiveTextEdit->setMinimumSize(QSize(500, 100));
	receiveTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	transmitButton = new QPushButton();
	transmitButton->setText(QString("Transmit"));
	transmitButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	
}

void gui::createLayouts() {

	leftLayout = new QVBoxLayout();
	leftLayout->setMargin(5);
	leftLayout->addWidget(transmitLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	leftLayout->addWidget(transmitTextEdit);
	leftLayout->addWidget(transmitButton, 0, Qt::AlignTop | Qt::AlignRight);
	leftLayout->addWidget(receiveLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	leftLayout->addWidget(receiveTextEdit);
	
	leftFrame->setLayout(leftLayout);

	rightLayout = new QVBoxLayout();
	rightLayout->setMargin(5);

	baseLayout = new QHBoxLayout();
	baseLayout->setMargin(0);
	baseLayout->addWidget(leftFrame);
	baseLayout->addWidget(rightFrame);
	
	baseFrame->setLayout(baseLayout);

	setCentralWidget(baseFrame);

}


void gui::slot_quit() {

	emit sig_quit();

	return;
}