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

	struct portSettings {
		QStringList availablePorts;
	};

	portSettings *settings;

public slots:

	void slot_updateCOMPorts(void*);

private slots:
	
	void slot_quit();

signals:

	void sig_getCOMPorts();
	
	void sig_quit();

};

#endif // !__GUI_HPP__