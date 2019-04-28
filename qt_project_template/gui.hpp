#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <QtWidgets/QMainWindow>

#include <QAction>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
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

	QFrame *baseFrame;

	QAction *quitAction;
	
	QMenu *fileMenu;

	QHBoxLayout *baseLayout;

public slots:

private slots:

	void slot_quit();

signals:

	void sig_quit();

};

#endif // !__GUI_HPP__