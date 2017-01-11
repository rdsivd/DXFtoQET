#include "elmt_entities.h"

#include <qsql.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QtSql>

extern struct DXF_base DXF_main_base[DXF_base_set];
extern struct DXF_Entities DXF_Entities_List;

elmt_entities::elmt_entities(QWidget *parent) : QWidget(parent)
{

	//connect (this ,SIGNAL (Signal1(const QString &)),DXF_main_base,SLOT(update_proces(const QString &)));
}

void elmt_entities::Open_SQL_DB (QString ELMT_filename)
{

	dbManager mydb2;
	mydb2.dbManager1(ELMT_filename);


}

void elmt_entities::Close_SQL_DB (QString ELMT_filename)
{

	dbManager mydb2;
	mydb2.dbManager_close(ELMT_filename);


}

QString elmt_entities::Get_Entities (QString ELMT_filename)
{

	DXF_main_base[0].QDXF_entitie_arc_color="black";
	DXF_main_base[0].QDXF_entitie_circle_color="black";
	DXF_main_base[0].QDXF_entitie_ellipse_color="black";
	DXF_main_base[0].QDXF_entitie_input_color="black";
	DXF_main_base[0].QDXF_entitie_line_color="black";
	DXF_main_base[0].QDXF_entitie_lwpolyline_color="red";
	DXF_main_base[0].QDXF_entitie_polyline_color="blue";
	DXF_main_base[0].QDXF_entitie_rectangel_color="black";
	DXF_main_base[0].QDXF_entitie_terminal_color="black";
	DXF_main_base[0].QDXF_entitie_text_color="black";
	DXF_main_base[0].QDXF_entitie_solid_color="green";

	xcount=0;
	Logtext="";
	rowcount=0;

	QSqlQuery NewQuery("SELECT * FROM dxf_entities");

	dxf_base_line New_DXF_Line;
	dxf_base_circle New_DXF_Circle;
	dxf_base_arc New_DXF_Arc;
	dxf_base_text New_DXF_Text;
	dxf_base_input New_DXF_Input;
	dxf_base_terminal New_DXF_Terminal;
	dxf_base_ellipse New_DXF_Ellipse;
	dxf_base_polyline New_DXF_Polyline;
	dxf_base_polyline New_DXF_LWPolyline;
	dxf_base_polyline New_DXF_SOLID;
	elmt_blocks New_DXF_blocks;

	// basic part for creating a correct ELMT file

	//DXF_Entities_List.DXF_Result.clear();

	Logtext.append("Insert basic ELMT items\n");

	Signal_waarde1.clear();
	Signal_waarde1.append("Insert basic ELMT items\n");

	emit Signal1(Signal_waarde1);

	/*  <text x="-11" y="3" size="6" rotation="90" text="Vcc"/>
		<text x="-7" y="-8" size="3" text="HC-SR04"/>
		<text x="-50" y="-45" text="Test" color="white" size="9"/>*/

	New_DXF_Input.QET_x=0;
	New_DXF_Input.QET_y=0;

	New_DXF_Input.QET_rotation=90;
	New_DXF_Input.QET_text="converted";
	New_DXF_Input.QET_size=1;
	New_DXF_Input.QET_text_style="default"	;


	//New_DXF_Text.QET_antialias="false";
	//New_DXF_Text.QET_line_style="normal";
	//New_DXF_Text.QET_line_weight="thin";
	//New_DXF_Text.QET_filling="none";
	New_DXF_Input.QET_rotate="true";
	New_DXF_Input.QET_tag="label";

	New_DXF_Input.QET_color=DXF_main_base[0].QDXF_entitie_text_color;


	DXF_Entities_List.DXF_Result.append(New_DXF_Input.Create_input());

	New_DXF_Terminal.QET_x=10;
	New_DXF_Terminal.QET_y=-10;
	New_DXF_Terminal.QET_orientation="sud";

	DXF_Entities_List.DXF_Result.append(New_DXF_Terminal.Create_terminal());


	Logtext.append("Converting DXF entities\n");

	Signal_waarde1.clear();
	Signal_waarde1.append("Converting DXF entities\n");

	emit Signal1(Signal_waarde1);

	//QSqlRecord Record2=NewQuery.record();


	while (NewQuery.next())
	{

		QSqlRecord Record2=NewQuery.record();
		Recordvalue=Record2.value("Command").toString();

		Signal_waarde1.clear();
		Signal_waarde1.append(Record2.value("Command").toString());
		Signal_waarde1.append(" : ");
		Signal_waarde1.append(Record2.value("dxf_5").toString());

		emit Signal1(Signal_waarde1);

		if (Record2.value("Command_count").toInt()==0)
		{

			ELMT_ID_instruction=Record2.value("ID_instruction").toString();
		}

		rowcount++;

		if (Record2.value("Command").toString()=="LINE" and Record2.value("Command_count").toInt()==0)
		{
			/*<line length1="1.5" length2="1.5" antialias="false"
			 * end1="none" end2="none"
			 * style="line-style:normal;line-weight:normal;filling:none;color:black"
			 * y1="-20" x1="10" y2="-10" x2="10"/>*/


			New_DXF_Line.QET_x1=Record2.value("dxf_10").toDouble();
			New_DXF_Line.QET_x2=Record2.value("dxf_11").toDouble();
			New_DXF_Line.QET_y1=Record2.value("dxf_20").toDouble();
			New_DXF_Line.QET_y2=Record2.value("dxf_21").toDouble();

			New_DXF_Line.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Line.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Line.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Line.QET_softID=Record2.value("dxf_330").toString();

			New_DXF_Line.QET_lenght1=1.5;
			New_DXF_Line.QET_lenght2=1.5;
			New_DXF_Line.QET_antialias="false";
			New_DXF_Line.QET_end1="none";
			New_DXF_Line.QET_end2="none";

			New_DXF_Line.QET_line_style="normal";
			New_DXF_Line.QET_line_weight="thin";
			New_DXF_Line.QET_filling="none";
			New_DXF_Line.QET_color=DXF_main_base[0].QDXF_entitie_line_color;


			DXF_Entities_List.DXF_Result.append(New_DXF_Line.CreateElmt());

		}

		if (Record2.value("Command").toString()=="CIRCLE" and Record2.value("Command_count").toInt()==0)
		{
			/* <circle x="-28" y="-8" antialias="true"
			 * style="line-style:normal;line-weight:thin;filling:none;color:black"
			 * diameter="22"/> */

			New_DXF_Circle.QET_x=Record2.value("dxf_10").toDouble();
			New_DXF_Circle.QET_y=Record2.value("dxf_20").toDouble();
			New_DXF_Circle.QET_diameter=Record2.value(("dxf_40")).toDouble();

			New_DXF_Circle.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Circle.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Circle.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Circle.QET_softID=Record2.value("dxf_330").toString();

			New_DXF_Circle.QET_antialias="false";
			New_DXF_Circle.QET_line_style="normal";
			New_DXF_Circle.QET_line_weight="thin";
			New_DXF_Circle.QET_filling="none";
			New_DXF_Circle.QET_color=DXF_main_base[0].QDXF_entitie_circle_color;


			DXF_Entities_List.DXF_Result.append(New_DXF_Circle.Create_circle());
		}

		if (Record2.value("Command").toString()=="ARC" and Record2.value("Command_count").toInt()==0)
		{
			/*  <arc width="20" x="-15" y="-8" antialias="true"
				height="38" style="line-style:normal;
				line-weight:normal;filling:none;color:black"
				start="-30" angle="-299"/> */

			New_DXF_Arc.QET_x=Record2.value("dxf_10").toDouble()-Record2.value("dxf_40").toDouble();
			New_DXF_Arc.QET_y=Record2.value("dxf_20").toDouble()+Record2.value("dxf_40").toDouble();
			New_DXF_Arc.QET_width=Record2.value("dxf_40").toDouble()*2;
			New_DXF_Arc.QET_height=Record2.value("dxf_40").toDouble()*2;
			New_DXF_Arc.QET_start=Record2.value("dxf_50").toDouble();
			New_DXF_Arc.QET_end=Record2.value("dxf_51").toDouble();

			New_DXF_Arc.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Arc.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Arc.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Arc.QET_softID=Record2.value("dxf_330").toString();


			New_DXF_Arc.QET_antialias="false";
			New_DXF_Arc.QET_line_style="normal";
			New_DXF_Arc.QET_line_weight="thin";
			New_DXF_Arc.QET_filling="none";
			New_DXF_Arc.QET_color=DXF_main_base[0].QDXF_entitie_circle_color;

			DXF_Entities_List.DXF_Result.append(New_DXF_Arc.Create_arc());
		}

		if (Record2.value("Command").toString()=="TEXT" and Record2.value("Command_count").toInt()==0)
		{
			/*  <text x="-11" y="3" size="6" rotation="90" text="Vcc"/>
				<text x="-7" y="-8" size="3" text="HC-SR04"/>
				<text x="-50" y="-45" text="Test" color="white" size="9"/>*/

			New_DXF_Text.QET_x=Record2.value("dxf_10").toDouble();
			New_DXF_Text.QET_y=Record2.value("dxf_20").toDouble();

			New_DXF_Text.QET_rotation=Record2.value("dxf_50").toDouble();
			New_DXF_Text.QET_text=Record2.value("dxf_1").toString();
			New_DXF_Text.QET_size=Record2.value("dxf_40").toDouble();
			New_DXF_Text.QET_text_style=Record2.value("dxf_7").toString();

			New_DXF_Text.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Text.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Text.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Text.QET_softID=Record2.value("dxf_330").toString();


			//New_DXF_Text.QET_antialias="false";
			//New_DXF_Text.QET_line_style="normal";
			//New_DXF_Text.QET_line_weight="thin";
			//New_DXF_Text.QET_filling="none";
			New_DXF_Text.QET_color=DXF_main_base[0].QDXF_entitie_circle_color;


			DXF_Entities_List.DXF_Result.append(New_DXF_Text.Create_text());
		}

		if (Record2.value("Command").toString()=="INPUT" and Record2.value("Command_count").toInt()==0)
		{
			/*  <text x="-11" y="3" size="6" rotation="90" text="Vcc"/>
				<text x="-7" y="-8" size="3" text="HC-SR04"/>
				<text x="-50" y="-45" text="Test" color="white" size="9"/>*/

			New_DXF_Input.QET_x=Record2.value("dxf_10").toDouble();
			New_DXF_Input.QET_y=Record2.value("dxf_20").toDouble();

			New_DXF_Input.QET_rotation=Record2.value("dxf_50").toDouble();
			New_DXF_Input.QET_text=Record2.value("dxf_1").toString();
			New_DXF_Input.QET_size=Record2.value("dxf_40").toDouble();
			New_DXF_Input.QET_text_style=Record2.value("dxf_7").toString();

			New_DXF_Input.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Input.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Input.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Input.QET_softID=Record2.value("dxf_330").toString();

			//New_DXF_Text.QET_antialias="false";
			//New_DXF_Text.QET_line_style="normal";
			//New_DXF_Text.QET_line_weight="thin";
			//New_DXF_Text.QET_filling="none";
			New_DXF_Input.QET_rotate="true";
			New_DXF_Input.QET_tag="none";

			New_DXF_Input.QET_color=DXF_main_base[0].QDXF_entitie_input_color;

			DXF_Entities_List.DXF_Result.append(New_DXF_Input.Create_input());
		}

		if (Record2.value("Command").toString()=="ATTRIB" and Record2.value("Command_count").toInt()==0)
		{			/*  <text x="-11" y="3" size="6" rotation="90" text="Vcc"/>
				<text x="-7" y="-8" size="3" text="HC-SR04"/>
				<text x="-50" y="-45" text="Test" color="white" size="9"/>*/

			New_DXF_Input.QET_x=Record2.value("dxf_10").toDouble();
			New_DXF_Input.QET_y=Record2.value("dxf_20").toDouble();

			New_DXF_Input.QET_rotation=Record2.value("dxf_50").toDouble();
			New_DXF_Input.QET_text=Record2.value("dxf_1").toString();
			New_DXF_Input.QET_size=Record2.value("dxf_40").toDouble();
			New_DXF_Input.QET_text_style=Record2.value("dxf_7").toString();

			New_DXF_Input.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Input.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Input.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Input.QET_softID=Record2.value("dxf_330").toString();
			New_DXF_Input.QET_dxf_tag=Record2.value("dxf_2").toString();


			//New_DXF_Text.QET_antialias="false";
			//New_DXF_Text.QET_line_style="normal";
			//New_DXF_Text.QET_line_weight="thin";
			//New_DXF_Text.QET_filling="none";
			New_DXF_Input.QET_rotate="true";
			New_DXF_Input.QET_tag="none";

			New_DXF_Input.QET_color=DXF_main_base[0].QDXF_entitie_input_color;


			DXF_Entities_List.DXF_Result.append(New_DXF_Input.Create_input());
		}

		if (Record2.value("Command").toString()=="POINT" and Record2.value("Command_count").toInt()==0)
		{
			/*  <text x="-11" y="3" size="6" rotation="90" text="Vcc"/>
				<text x="-7" y="-8" size="3" text="HC-SR04"/>
				<text x="-50" y="-45" text="Test" color="white" size="9"/>*/

			New_DXF_Terminal.QET_x=Record2.value("dxf_10").toDouble();
			New_DXF_Terminal.QET_y=Record2.value("dxf_20").toDouble();

			New_DXF_Terminal.QET_orientation="sud";//Record2.value("dxf_50").toDouble();
			//New_DXF_Input.QET_text=Record2.value("dxf_1").toString();
			//New_DXF_Input.QET_size=Record2.value("dxf_40").toDouble();
			//New_DXF_Input.QET_text_style=Record2.value("dxf_7").toString();

			New_DXF_Terminal.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Terminal.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Terminal.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Terminal.QET_softID=Record2.value("dxf_330").toString();


			//New_DXF_Text.QET_antialias="false";
			//New_DXF_Text.QET_line_style="normal";
			//New_DXF_Text.QET_line_weight="thin";
			//New_DXF_Text.QET_filling="none";
			//New_DXF_Input.QET_rotate="true";
			//New_DXF_Input.QET_tag="label";

			//New_DXF_Input.QET_color=DXF_main_base[0].QDXF_circle_color;


			DXF_Entities_List.DXF_Result.append(New_DXF_Terminal.Create_terminal());
		}

		if (Record2.value("Command").toString()=="ELLIPSE" and Record2.value("Command_count").toInt()==0)
		{
			/*  <text x="-11" y="3" size="6" rotation="90" text="Vcc"/>
				<text x="-7" y="-8" size="3" text="HC-SR04"/>
				<text x="-50" y="-45" text="Test" color="white" size="9"/>*/

			New_DXF_Ellipse.QET_center_x=Record2.value("dxf_10").toDouble();
			New_DXF_Ellipse.QET_center_y=Record2.value("dxf_20").toDouble();
			New_DXF_Ellipse.QET_major_radius_x=Record2.value("dxf_11").toDouble();
			New_DXF_Ellipse.QET_major_radius_y=Record2.value("dxf_21").toDouble();

			New_DXF_Ellipse.QET_end_parameter=Record2.value("dxf_42").toDouble();
			New_DXF_Ellipse.QET_Start_parameter=Record2.value("dxf_41").toDouble();
			New_DXF_Ellipse.QET_ratio_minor_axis=Record2.value("dxf_40").toDouble();

			New_DXF_Ellipse.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Ellipse.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Ellipse.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Ellipse.QET_softID=Record2.value("dxf_330").toString();

			//New_DXF_Terminal.QET_orientation="sud";//Record2.value("dxf_50").toDouble();
			//New_DXF_Input.QET_text=Record2.value("dxf_1").toString();
			//New_DXF_Input.QET_size=Record2.value("dxf_40").toDouble();
			//New_DXF_Input.QET_text_style=Record2.value("dxf_7").toString();


			New_DXF_Ellipse.QET_antialias="false";
			New_DXF_Ellipse.QET_line_style="normal";
			New_DXF_Ellipse.QET_line_weight="thin";
			New_DXF_Ellipse.QET_filling="none";
			//New_DXF_Ellipse.QET_rotate="true";
			//New_DXF_Input.QET_tag="label";

			New_DXF_Ellipse.QET_color=DXF_main_base[0].QDXF_entitie_ellipse_color;


			DXF_Entities_List.DXF_Result.append(New_DXF_Ellipse.Create_ellipse());
		}

		if (Record2.value("Command").toString()=="POLYLINE" and Record2.value("Command_count").toInt()==0)
		{
			New_DXF_Polyline.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_Polyline.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_Polyline.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_Polyline.QET_softID=Record2.value("dxf_330").toString();

			New_DXF_Polyline.QET_antialias="false";
			New_DXF_Polyline.QET_line_style="normal";
			New_DXF_Polyline.QET_line_weight="thin";
			New_DXF_Polyline.QET_filling="none";

			New_DXF_Polyline.QET_color=DXF_main_base[0].QDXF_entitie_polyline_color;

			if (Record2.value("dxf_70").toInt()==1)
			{
				New_DXF_Polyline.QET_closed="true";
			}
			else
			{
				New_DXF_Polyline.QET_closed="false";
			}

			end_seqend=0;
			count_vertex=0;

			while (end_seqend==0 and count_vertex<QET_L_POLYLINE)
			{
				NewQuery.next();
				QSqlRecord Record3=NewQuery.record();
				Recordvalue2=Record3.value("Command").toString();

				if (Record3.value("Command").toString()=="VERTEX" and Record3.value("Command_count").toInt()==0)
				{
					New_DXF_Polyline.QET_x[count_vertex]=Record3.value("dxf_10").toDouble();
					New_DXF_Polyline.QET_y[count_vertex]=Record3.value("dxf_20").toDouble();
					count_vertex++;

				}
				else
				{
					if (Record3.value("Command").toString()=="SEQEND" and Record3.value("Command_count").toInt()==0)
					{
						end_seqend=1;
					}

					//count_vertex++;
				}
				if (Record3.value("Command").toString()=="SEQEND" and Record3.value("Command_count").toInt()==0)
				{
					end_seqend=1;
				}

			}

			Signal_waarde1.clear();
			Signal_waarde1.append(Record2.value("Command").toString());
			Signal_waarde1.append(" : ");
			Signal_waarde1.append(Record2.value("dxf_5").toString());
			Signal_waarde1.append(" : maxvertex => ");
			Signal_waarde1.append(Record2.value("dxf_90").toString());
			Signal_waarde1.append(" : count vertex => ");
			Signal_waarde1.append(QString::number(count_vertex));
			//Signal_waarde1.append(" : ");
			//Signal_waarde1.append();

			emit Signal1(Signal_waarde1);


			New_DXF_Polyline.segments=count_vertex;

			DXF_Entities_List.DXF_Result.append(New_DXF_Polyline.Create_polyline());


		}

		if (Record2.value("Command").toString()=="INSERT" and Record2.value("Command_count").toInt()==0)
		{

			New_DXF_blocks.Block_name=Record2.value("dxf_2").toString();
			New_DXF_blocks.Block_X=Record2.value("dxf_10").toDouble();
			New_DXF_blocks.Block_Y=Record2.value("dxf_20").toDouble();

			New_DXF_blocks.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_blocks.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_blocks.QET_handle=Record2.value("dxf_2").toString();//Record2.value("dxf_5").toString();
			New_DXF_blocks.QET_softID=Record2.value("dxf_330").toString();


			New_DXF_blocks.Block_scale_x=Record2.value("dxf_41").toDouble();
			if (New_DXF_blocks.Block_scale_x==0)
			{
				New_DXF_blocks.Block_scale_x=1;
			}
			New_DXF_blocks.Block_scale_y=Record2.value("dxf_42").toDouble();
			if (New_DXF_blocks.Block_scale_y==0)
			{
				New_DXF_blocks.Block_scale_y=1;
			}
			New_DXF_blocks.Block_rotation=Record2.value("dxf_43").toDouble();

			New_DXF_blocks.FromBlock="Inserted from entitie ";

			Logtext.append("Inserted from entitie block : ");
			Logtext.append(Record2.value("dxf_2").toString());
			Logtext.append(" will be converted as a drawing part");
			Logtext.append(" \n");

			Logtext.append(New_DXF_blocks.Insert_Block());
		}

		if (Record2.value("Command").toString()=="LWPOLYLINE" and Record2.value("Command_count").toInt()==0)
		{

			New_DXF_LWPolyline.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_LWPolyline.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_LWPolyline.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_LWPolyline.QET_softID=Record2.value("dxf_330").toString();

			New_DXF_LWPolyline.QET_antialias="false";
			New_DXF_LWPolyline.QET_line_style="normal";
			New_DXF_LWPolyline.QET_line_weight="thin";
			New_DXF_LWPolyline.QET_filling="none";

			New_DXF_LWPolyline.QET_color=DXF_main_base[0].QDXF_entitie_polyline_color;

			if (Record2.value("dxf_70").toInt()==1)
			{
				New_DXF_LWPolyline.QET_closed="true";
			}
			else
			{
				New_DXF_LWPolyline.QET_closed="false";
			}

			end_lwpoly=0;
			max_vertex=0;
			count_vertex=0;

			max_vertex=Record2.value("dxf_90").toInt();

			if (max_vertex >=QET_L_POLYLINE)
			{
				Logtext.append("max_vertex :  ");
				Logtext.append(QString::number(max_vertex));
				Logtext.append(" > ");
				Logtext.append(QString::number(QET_L_POLYLINE));
				Logtext.append(" \n");
			}



			while (end_lwpoly==0 and count_vertex<max_vertex+1)
			{
				NewQuery.next();
				QSqlRecord Record3=NewQuery.record();
				Recordvalue2=Record3.value("Command").toString();
				comand_count2=Record3.value("Command_count").toInt();

				if (Record3.value("Command").toString()=="LWPOLYLINE" and max_vertex<QET_L_POLYLINE)
				{
					New_DXF_LWPolyline.QET_x[count_vertex]=Record3.value("dxf_10").toDouble();
					New_DXF_LWPolyline.QET_y[count_vertex]=Record3.value("dxf_20").toDouble();
					count_vertex++;

				}
				else
				{
					if (count_vertex>max_vertex)
					{
						end_lwpoly=1;
					}

					//count_vertex++;
				}

				if (count_vertex>max_vertex)
				{
					end_lwpoly=1;
				}

			}

			New_DXF_LWPolyline.segments=count_vertex;

			DXF_Entities_List.DXF_Result.append(New_DXF_LWPolyline.Create_polyline());

			Signal_waarde1.clear();
			Signal_waarde1.append(Record2.value("Command").toString());
			Signal_waarde1.append(" : ");
			Signal_waarde1.append(Record2.value("dxf_5").toString());
			Signal_waarde1.append(" : maxvertex => ");
			Signal_waarde1.append(Record2.value("dxf_90").toString());
			Signal_waarde1.append(" : count vertex => ");
			Signal_waarde1.append(QString::number(count_vertex));
			//Signal_waarde1.append(" : ");
			//Signal_waarde1.append();

			emit Signal1(Signal_waarde1);

		}

		if (Record2.value("Command").toString()=="SOLID" and Record2.value("Command_count").toInt()==0)
		{

			New_DXF_SOLID.QET_layer=Record2.value("dxf_8").toString();
			New_DXF_SOLID.QET_ltype=Record2.value("dxf_6").toString();
			New_DXF_SOLID.QET_handle=Record2.value("dxf_5").toString();
			New_DXF_SOLID.QET_softID=Record2.value("dxf_330").toString();

			New_DXF_SOLID.QET_antialias="false";
			New_DXF_SOLID.QET_line_style="normal";
			New_DXF_SOLID.QET_line_weight="thin";
			New_DXF_SOLID.QET_filling="none";

			New_DXF_SOLID.QET_color=DXF_main_base[0].QDXF_entitie_solid_color;

			if (Record2.value("dxf_70").toInt()==1)
			{
				New_DXF_SOLID.QET_closed="true";
			}
			else
			{
				New_DXF_SOLID.QET_closed="false";
			}

			end_lwpoly=0;
			max_vertex=0;
			count_vertex=0;

			//max_vertex=Record2.value("dxf_90").toInt();
			max_vertex=4;

			if (max_vertex >=QET_L_POLYLINE)
			{
				Logtext.append("max_vertex :  ");
				Logtext.append(QString::number(max_vertex));
				Logtext.append(" > ");
				Logtext.append(QString::number(QET_L_POLYLINE));
				Logtext.append(" \n");
			}

			/*while (end_lwpoly==0 and count_vertex<max_vertex+1)
			{
				NewQuery.next();
				QSqlRecord Record3=NewQuery.record();
				Recordvalue2=Record3.value("Command").toString();

				if (Record3.value("Command").toString()=="SOLID" and max_vertex<QET_L_POLYLINE)*/
				//{
					New_DXF_SOLID.QET_x[0]=Record2.value("dxf_10").toDouble();
					New_DXF_SOLID.QET_y[0]=Record2.value("dxf_20").toDouble();

					New_DXF_SOLID.QET_x[1]=Record2.value("dxf_11").toDouble();
					New_DXF_SOLID.QET_y[1]=Record2.value("dxf_21").toDouble();

					New_DXF_SOLID.QET_x[3]=Record2.value("dxf_12").toDouble();
					New_DXF_SOLID.QET_y[3]=Record2.value("dxf_22").toDouble();

					New_DXF_SOLID.QET_x[2]=Record2.value("dxf_13").toDouble();
					New_DXF_SOLID.QET_y[2]=Record2.value("dxf_23").toDouble();
					count_vertex=3;

				/*}
				if (count_vertex>max_vertex)
				{
					end_lwpoly=1;
				}

			}*/

			New_DXF_SOLID.segments=count_vertex;

			DXF_Entities_List.DXF_Result.append(New_DXF_SOLID.Create_polyline());


		}

	}

	Logtext.append("Records ENTITIE passed : ");
	Logtext.append(QString::number(rowcount));
	Logtext.append(" \n");
	return Logtext;
}
