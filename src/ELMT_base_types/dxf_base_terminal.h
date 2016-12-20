#ifndef DXF_BASE_TERMINAL_H
#define DXF_BASE_TERMINAL_H

//#include <QMainWindow>
#include <QWidget>
#include <QObject>

class dxf_base_terminal : public QWidget // QMainWindow
{
	Q_OBJECT
	public:
	explicit dxf_base_terminal(QWidget *parent = 0);

	QString Result;



	//QET xml var
	double QET_x;
	double QET_y;
	QString QET_orientation;



	QString Create_terminal();

	signals:

	public slots:

};

#endif // DXF_BASE_TERMINAL_H
