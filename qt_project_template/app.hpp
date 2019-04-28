#ifndef __APP_HPP__
#define __APP_HPP__

#include <QObject>

class App : public QObject 
{

	Q_OBJECT

public:

	App();

	~App();

private:


public slots:

	void slot_init();

private slots:

signals:

};

#endif //!__APP_HPP__