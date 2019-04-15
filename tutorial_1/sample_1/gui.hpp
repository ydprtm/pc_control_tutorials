#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <QtWidgets/QMainWindow>

#include <QAction>
#include <QComboBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QWidget>

class gui : public QMainWindow
{
	Q_OBJECT

public:
	gui(QWidget *parent = Q_NULLPTR);
	~gui();

private:

	void createWidgets();
	void createActions();
	void createMenus();
	void createLayouts();

	QAction *quitAction;
	
	QMenu *fileMenu;

	QFrame *baseWindow;
	QFrame *serialTerminalWindow;
	QFrame *serialOptionsWindow;

	QLabel *portLabel;
	QComboBox *portCombo;
	QLabel *baudLabel;
	QComboBox *baudCombo;
	QLabel *packetSizeLabel;
	QComboBox *packetSizeCombo;
	QLabel *parityLabel;
	QComboBox *parityCombo;
	QLabel *stopBitsLabel;
	QComboBox *stopBitsCombo;

	QPushButton *transmitButton;

	QHBoxLayout *baseLayout;
	QVBoxLayout *serialTerminalLayout;
	QVBoxLayout *serialOptionsLayout;

	QTextEdit *serialTerminal;

	struct portOptions {
		QStringList comPorts;
		QStringList baudRates;
		QStringList packetSize;
		QStringList parity;
		QStringList stopBits;
	};

	struct portSettings {
		QString comPort;
		int baudRate;
		int packetSize;
		int parity;
		int stopBits;
	};

	portOptions *options;
	portSettings *settings;

public slots:

	void slot_updateOptions(void*);

private slots:
	
	void slot_portChanged();
	void slot_baudRateChanged();
	void slot_packetSizeChanged();
	void slot_parityChanged();
	void slot_stopBitsChanged();

	void slot_quit();

signals:

	void sig_getOptions();

	void sig_updateSettings(void*);
	
	void sig_quit();

};


#endif // !__GUI_HPP__