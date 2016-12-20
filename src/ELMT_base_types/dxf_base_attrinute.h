#ifndef DXF_ENTITIE_ATTRINUTE_H
#define DXF_ENTITIE_ATTRINUTE_H

//#include <QMainWindow>
#include <QWidget>
#include "src/dxf/dxf_attr.h"
#include "src/dxf_data.h"
#include "src/dxf_table_size.h"
#include "src/qet_base_types/baseelmt.h"
#include "src/dxf_control/dxf_text_control.h"

class dxf_entitie_attrinute : public QWidget //QMainWindow
{
	Q_OBJECT
	public:
	explicit dxf_entitie_attrinute(QWidget *parent = 0);

	QString Result_attr;
	QString Entitie_color;			// black
	QString Entitie_line_weight;
	QString Entitie_filling;
	QString Entitie_antialias;
	QString Entitie_rotate;			// true
	QString Entitie_tag;			// label

	int Count_lines;
	int Count_entitie_attr;

	QString dxf_entitie_make_attribute();
	signals:

	public slots:
};

#endif // DXF_ENTITIE_ATTRINUTE_H
