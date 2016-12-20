#include "dxf_base_terminal.h"

dxf_base_terminal::dxf_base_terminal(QWidget *parent) :
	QWidget(parent)
{
}

QString dxf_base_terminal::Create_terminal()
{

	/*QET_x="0";
	QET_y="0";
	QET_orientation="n";*/

	 /* <terminal x="-10" y="-20" orientation="n"/> */

	Result.append("     ");
	Result.append("<terminal");
	Result.append(" x=");
	Result.append(QChar(34));
	Result.append(QString::number(QET_x,'f',2));
	Result.append(QChar(34));
	Result.append(" y=");
	Result.append(QChar(34));
	Result.append(QString::number(-QET_y,'f',2));
	Result.append(QChar(34));
	Result.append(" orientation=");

	Result.append(QChar(34));
	Result.append("s");
	Result.append(QChar(34));

	Result.append(" />");
	Result.append('\n');

	return Result;

}
