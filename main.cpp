#include "dxftoqet3db.h"
#include <QApplication>

#include "data.h"


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	DXFtoQET3DB w;
	w.show();

	return a.exec();
}
