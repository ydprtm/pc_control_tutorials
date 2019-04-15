#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <QtWidgets/QMainWindow>

#include <QAction>
#include <QComboBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
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

	void createActions();
	void createMenus();
	void createWidgets();
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
	QLabel *stopBitsLabel;
	QComboBox *stopBitsCombo;
	QLabel *parityLabel;
	QComboBox *parityCombo;

	QPushButton *transmitButton;

	QHBoxLayout *baseLayout;
	QVBoxLayout *serialTerminalLayout;
	QVBoxLayout *serialOptionsLayout;

	QTextEdit *serialTerminal;

	struct portSettings {
		int comPort{ 1 };
	};

	portSettings *settings;

public slots:

	void slot_updateSettings(void*);

private slots:
	
	void slot_quit();

signals:

	void sig_getSettings();

	void sig_quit();

};


#endif // !__GUI_HPP__