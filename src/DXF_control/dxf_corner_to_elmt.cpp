#include "dxf_corner_to_elmt.h"

dxf_corner_to_elmt::dxf_corner_to_elmt(QWidget *parent) : QWidget(parent)
{

}

double dxf_corner_to_elmt::QET_start_angle()
{

/*    if (start_angle >=0 and start_angle<=90)
    {
        begin1=90-start_angle;

    }
    else
    {
        begin1=450-start_angle;

    }*/

    begin1=start_angle;

/*	begin1=450-start_angle;


	if (begin1>360)
	{
		begin0=begin1-360;
	}
	else
	{
		if(begin1<0)
		{
			begin0=360-begin1;
		}
		else
		{
			begin0=begin1;
		}
    }*/

    if (begin1 < 0)
    {
        begin1 = -begin1;
    }

    return begin1;
}




double dxf_corner_to_elmt::QET_end_angle()
{
    /*if (end_angle >=0 and end_angle<=90)
    {
        einde0=90-end_angle;

    }
    else
    {
        einde0=450-end_angle;

    }*/
    einde1=end_angle;

/*	einde1=450-end_angle;

	if (einde1>360)
	{
		einde0=einde1-360;
	}
	else
	{
		if (einde1<0)
		{
			einde0=einde1-360;
		}
		else
		{
			einde0=einde1;
		}
    }*/


    return einde1;
}




double dxf_corner_to_elmt::QET_corner_angle()
{
    /*if (begin2>einde2)
	{
		N=einde2-begin2;
	}
	else
	{
		N=einde2-begin2-360;
	}

	if (N<0)
	{
		O=-N;
	}
	else
	{
		O=N;
	}

	J=end_angle2-start_angle2+N;
	K=360-end_angle2;
	L=360-start_angle2;
	M=K-L;
	R=-O;
	S=J-O;

	if (S < -360)
	{
		T=S+360;
	}
	else
	{
		T=S;
	}

	if (begin2<einde2)
	{
		U=M;
	}
	else
	{
		U=T;
	}

	if (U<0)
	{
		V=-U;
	}
	else
	{
		V=U;
	}

	W=U+V;

    if (W==0.0)
	{
		hoek2=-V;
	}
	else
	{
		hoek2=T;
    }*/

    if (start_angle2 > end_angle2)
    {
        hoek2 = (360-start_angle2)+end_angle2;
    }
    else
    {
        hoek2 = end_angle2-start_angle2;
    }

    //return -hoek2;
    if (hoek2<0.0)
    {
        hoek2=-hoek2;
    }
    return hoek2;
}
