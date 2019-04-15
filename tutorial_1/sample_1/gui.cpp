#include "gui.hpp"

gui::gui(QWidget *parent)
	: QMainWindow(parent)
{

	setMinimumSize(QSize(640, 480));

	createWidgets();
	createActions();
	createMenus();
	createLayouts();

	options = new portOptions();
	settings = new portSettings();

	emit sig_getOptions();

	return;
	
}

gui::~gui() {

}

void gui::createActions() {

	quitAction = new QAction(tr("&Quit"), this);
	quitAction->setShortcut(QKeySequence::Quit);
	connect(quitAction, SIGNAL(triggered()), this, SLOT(slot_quit()));

	connect(stopBitsCombo, SIGNAL(activated(int)), this, SLOT(slot_stopBitsChanged()));

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

void gui::slot_updateOptions(void *data) {

	options = static_cast<portOptions*>(data);

	for (const auto &c : options->comPorts) {

		portCombo->addItem(c);

	}

	for (const auto &b : options->baudRates) {

		baudCombo->addItem(b);

	}
	
	for (const auto &p : options->packetSize) {

		packetSizeCombo->addItem(p);

	}

	for (const auto &p : options->parity) {

		parityCombo->addItem(p);

	}

	for (const auto &s : options->stopBits) {

		stopBitsCombo->addItem(s);
	}

	
	baudCombo->setCurrentIndex(6);
	packetSizeCombo->setCurrentIndex(3);
	parityCombo->setCurrentIndex(0);
	stopBitsCombo->setCurrentIndex(0);

	settings->comPort = portCombo->currentText();
	settings->baudRate = baudCombo->currentIndex();
	settings->packetSize = packetSizeCombo->currentIndex();
	settings->parity = parityCombo->currentIndex();
	settings->stopBits = stopBitsCombo->currentIndex();

	void *set = static_cast<void*>(settings);

	emit sig_updateSettings(set);

}

void gui::slot_portChanged() {

}

void gui::slot_baudRateChanged() {

}

void gui::slot_packetSizeChanged() {

}

void gui::slot_parityChanged() {

}

void gui::slot_stopBitsChanged() {

	settings->stopBits = stopBitsCombo->currentIndex();

	void *data = static_cast<void*>(settings);

	emit sig_updateSettings(data);

}

void gui::slot_quit() {

	emit sig_quit();

	return;
}