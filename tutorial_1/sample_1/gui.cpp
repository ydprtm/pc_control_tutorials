#include "gui.hpp"

gui::gui(QWidget *parent)
	: QMainWindow(parent)
{

	setMinimumSize(QSize(640, 480));

	createWidgets();
	createActions();
	createMenus();
	createLayouts();

	emit sig_getCOMPorts();

	return;
	
}

gui::~gui() {

}

void gui::createActions() {

	quitAction = new QAction(tr("&Quit"), this);
	quitAction->setShortcut(QKeySequence::Quit);
	connect(quitAction, SIGNAL(triggered()), this, SLOT(slot_quit()));

	connect(openButton, SIGNAL(clicked()), this, SLOT(slot_openButtonClicked()));

	connect(transmitButton, SIGNAL(clicked()), this, SLOT(slot_transmitButtonClicked()));

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

	transmitLineEdit = new QLineEdit();
	transmitLineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	receiveLabel = new QLabel();
	receiveLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	receiveLabel->setText(QString("Receive"));

	receiveTextEdit = new QTextEdit();
	receiveTextEdit->setMinimumSize(QSize(500, 100));
	receiveTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	transmitButton = new QPushButton();
	transmitButton->setText(QString("Transmit"));
	transmitButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	portLabel = new QLabel();
	portLabel->setText(QString("COM Port"));

	portCombo = new QComboBox();

	baudRateLabel = new QLabel();
	baudRateLabel->setText(QString("Baud Rate"));

	baudRateCombo = new QComboBox();
	baudRateCombo->addItem(QString::number(4800));
	baudRateCombo->addItem(QString::number(9600)); 
	baudRateCombo->addItem(QString::number(14400));
	baudRateCombo->addItem(QString::number(19200));
	baudRateCombo->addItem(QString::number(38400));
	baudRateCombo->addItem(QString::number(57600));
	baudRateCombo->addItem(QString::number(115200));
	baudRateCombo->addItem(QString::number(128000));
	baudRateCombo->setCurrentIndex(6);

	dataSizeLabel = new QLabel();
	dataSizeLabel->setText(QString("Data Size"));
	
	dataSizeCombo = new QComboBox();
	dataSizeCombo->addItem(QString::number(5));
	dataSizeCombo->addItem(QString::number(6));
	dataSizeCombo->addItem(QString::number(7));
	dataSizeCombo->addItem(QString::number(8));
	dataSizeCombo->setCurrentIndex(3);

	parityLabel = new QLabel();
	parityLabel->setText(QString("Parity"));
	
	parityCombo = new QComboBox();
	parityCombo->addItem(QString("None"));
	parityCombo->addItem(QString("Even"));
	parityCombo->addItem(QString("Odd"));
	parityCombo->setCurrentIndex(0);

	stopBitsLabel = new QLabel();
	stopBitsLabel->setText(QString("Stop Bits"));
	
	stopBitsCombo = new QComboBox();
	stopBitsCombo->addItem(QString::number(1));
	stopBitsCombo->addItem(QString::number(1.5));
	stopBitsCombo->addItem(QString::number(2));
	stopBitsCombo->setCurrentIndex(0);

	openButton = new QPushButton();
	openButton->setText(QString("Open"));

}

void gui::createLayouts() {

	leftLayout = new QVBoxLayout();
	leftLayout->setMargin(5);
	leftLayout->addWidget(transmitLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	leftLayout->addWidget(transmitLineEdit);
	leftLayout->addWidget(transmitButton, 0, Qt::AlignTop | Qt::AlignRight);
	leftLayout->addWidget(receiveLabel, 0, Qt::AlignTop | Qt::AlignLeft);
	leftLayout->addWidget(receiveTextEdit);
	
	leftFrame->setLayout(leftLayout);

	rightLayout = new QVBoxLayout();
	rightLayout->setMargin(5);
	rightLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	rightLayout->addWidget(portLabel);
	rightLayout->addWidget(portCombo);
	rightLayout->addWidget(baudRateLabel);
	rightLayout->addWidget(baudRateCombo);
	rightLayout->addWidget(dataSizeLabel);
	rightLayout->addWidget(dataSizeCombo);
	rightLayout->addWidget(parityLabel);
	rightLayout->addWidget(parityCombo);
	rightLayout->addWidget(stopBitsLabel);
	rightLayout->addWidget(stopBitsCombo);
	rightLayout->addWidget(openButton);

	rightFrame->setLayout(rightLayout);

	baseLayout = new QHBoxLayout();
	baseLayout->setMargin(0);
	baseLayout->addWidget(leftFrame);
	baseLayout->addWidget(rightFrame);
	
	baseFrame->setLayout(baseLayout);

	setCentralWidget(baseFrame);

}

void gui::slot_updateCOMPorts(void *data) {

	struct dataStruct {
		QList<QString> COMPorts;
	};

	dataStruct *d = static_cast<dataStruct*>(data);

	for (const auto &i : d->COMPorts) {
		portCombo->addItem(i);
	}

	return;
}

void gui::slot_openButtonClicked() {

	struct dataStruct {
		QString portName;
		QString baudRate;
		QString dataSize;
		QString parity;
		QString stopBits;
	};

	dataStruct *data = new dataStruct();

	data->portName = portCombo->currentText();
	data->baudRate = baudRateCombo->currentText();
	data->dataSize = dataSizeCombo->currentText();
	data->parity = parityCombo->currentText();
	data->stopBits = stopBitsCombo->currentText();

	emit sig_openPort(static_cast<void*>(data));

}

void gui::slot_transmitButtonClicked() {

	emit sig_transmitString(transmitLineEdit->text());

	return;
}

void gui::slot_receiveString(const QString &data) {

	receiveTextEdit->append(data);

}

void gui::slot_quit() {

	emit sig_quit();

	return;
}