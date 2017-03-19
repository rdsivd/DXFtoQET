#include "dxftoqet3db.h"
#include <QApplication>

#include "data.h"


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	DXFtoQET3DB w;
	w.show();

	//ui->Info_2->activateWindow();

	return a.exec();
}
