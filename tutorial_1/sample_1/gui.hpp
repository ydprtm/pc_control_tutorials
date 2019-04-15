#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <QtWidgets/QMainWindow>

#include <QAction>
#include <QMenu>
#include <QMenuBar>

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
	
	QAction *quitAction;
	
	QMenu *fileMenu;

public slots:


private slots:

	void slot_quit();

signals:

	void sig_quit();

};


#endif // !__GUI_HPP__