#include "gui.hpp"

gui::gui(QWidget *parent)
	: QMainWindow(parent)
{

	setMinimumSize(QSize(640, 480));

	createWidgets();
	createActions();
	createMenus();
	createLayouts();

	settings = new portSettings();

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

	portLabel = new QLabel();
	portLabel->setText(tr("COM Port"));
	portCombo = new QComboBox();	

	baudLabel = new QLabel();
	baudLabel->setText(tr("Baud Rate"));
	baudCombo = new QComboBox();
	
	packetSizeLabel = new QLabel();
	packetSizeLabel->setText(tr("Packet Size"));
	packetSizeCombo = new QComboBox();

	stopBitsLabel = new QLabel();
	stopBitsLabel->setText(tr("Stop Bits"));
	stopBitsCombo = new QComboBox();

	parityLabel = new QLabel();
	parityLabel->setText(tr("Parity"));
	parityCombo = new QComboBox();

	transmitButton = new QPushButton();
	transmitButton->setText("Transmit");

	baseWindow = new QFrame();
	baseWindow->setMinimumSize(QSize(480, 240));
	baseWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	serialTerminalWindow = new QFrame();
	serialTerminalWindow->setMinimumSize(QSize(380, 240));
	serialTerminalWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	serialOptionsWindow = new QFrame();
	serialOptionsWindow->setMinimumSize(QSize(100, 240));
	serialOptionsWindow->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

	serialTerminal = new QTextEdit();
	serialTerminal->setMinimumSize(QSize(360, 240));
	serialTerminal->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}

void gui::createLayouts() {
	
	serialTerminalLayout = new QVBoxLayout();
	serialTerminalLayout->setAlignment(Qt::AlignTop);
	serialTerminalLayout->setMargin(0);
	serialTerminalLayout->addWidget(serialTerminal);

	serialTerminalWindow->setLayout(serialTerminalLayout);

	serialOptionsLayout = new QVBoxLayout();
	serialOptionsLayout->setAlignment(Qt::AlignTop);
	serialOptionsLayout->setMargin(0);
	serialOptionsLayout->addWidget(portLabel);
	serialOptionsLayout->addWidget(portCombo);
	serialOptionsLayout->addWidget(baudLabel);
	serialOptionsLayout->addWidget(baudCombo);
	serialOptionsLayout->addWidget(packetSizeLabel);
	serialOptionsLayout->addWidget(packetSizeCombo);
	serialOptionsLayout->addWidget(parityLabel);
	serialOptionsLayout->addWidget(parityCombo);
	serialOptionsLayout->addWidget(stopBitsLabel);
	serialOptionsLayout->addWidget(stopBitsCombo);
	serialOptionsLayout->addWidget(transmitButton);

	serialOptionsWindow->setLayout(serialOptionsLayout);	

	baseLayout = new QHBoxLayout();
	baseLayout->setAlignment(Qt::AlignTop);
	baseLayout->setMargin(5);
	baseLayout->addWidget(serialTerminalWindow);
	baseLayout->addWidget(serialOptionsWindow);
	
	baseWindow->setLayout(baseLayout);

	setCentralWidget(baseWindow);

}

void gui::slot_updateCOMPorts(void*) {


}


void gui::slot_quit() {

	emit sig_quit();

	return;
}