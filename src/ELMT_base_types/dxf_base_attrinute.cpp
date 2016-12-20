#include "dxf_entitie_attrinute.h"

extern struct ALG Max_alg;
extern struct BLOCK Max_block;
extern struct ENTITIE Max_entitie;
extern struct DXF_base DXF_main_base[1];
extern struct DXF_entities_attrib DXF_input_entities_attrib[DXF_LE_ATTRIB];

dxf_entitie_attrinute::dxf_entitie_attrinute(QWidget *parent) : QWidget(parent)//: QMainWindow(parent)
{

}

QString dxf_entitie_attrinute::dxf_entitie_make_attribute()
{

	dxf_attr dxb_attr;
	DXF_Text_control db_txt_check2;

	Result_attr ="";

	Count_lines=0;

	while (Count_lines<=Count_entitie_attr)
	{

	   dxb_attr.x=DXF_input_entities_attrib[Count_lines].DXF_entities_attrib_code_10;					// x start
	   dxb_attr.y=-DXF_input_entities_attrib[Count_lines].DXF_entities_attrib_code_20;					// y start
	   dxb_attr.rotation=DXF_input_entities_attrib[Count_lines].DXF_entities_attrib_code_50;			//text rotation
	   dxb_attr.size=DXF_input_entities_attrib[Count_lines].DXF_entities_attrib_code_40;				//text height
	   dxb_attr.tag=Entitie_tag; //DXF_input_entities_attrib[Count_lines].DXF_entities_attrib_code_2;		// tag
	   dxb_attr.rotate=Entitie_rotate;
	   dxb_attr.color_attrib=Entitie_color;

	   db_txt_check2.TextToCheck=DXF_input_entities_attrib[Count_lines].DXF_entities_attrib_code_1;	// value

	   dxb_attr.text=db_txt_check2.Text_control();

	   Result_attr.append(dxb_attr.Create_ATTR());

	   Count_lines=Count_lines+1;


	}

	return Result_attr;
}
