#include "StdAfx.h"
#include "Hinhtron.h"
#include"math.h"



void Hinhtron::thietlap(int mx1,int my1,int mx3,int my3)
{
	
	x1 = mx1;
	y1 = my1;
	x3 = mx3;
	y3 = my3;
}

void Hinhtron::vehinh(CClientDC *pDC)

{
	int a, b, c, d;
	a = x3 - x1;
	b = y3 - y1;

	c = x1 - x3;
	d = y1 - y3;
	if (y1 < y3 && x1 < x3)
	{
		if (a > b)
		{
			pDC->Ellipse(x1, y1, x1 + b, y3);
		}
		else
		{
			pDC->Ellipse(x1, y1, x3, y1 + a);
		}
	}
	else
	{
		if (y1 < y3 && x1 > x3)
		{
			if (c > b)
			{
				pDC->Ellipse(x1, y1, x1 - b, y3);
			}
			else
			{
				pDC->Ellipse(x1, y1, x3, y1 + c);
			}
		}
		else
		{
			if (y1 > y3 && x1 > x3)
			{
				if (c > d)
				{
					pDC->Ellipse(x3, y3, x3 + d, y1);
				}
				else
				{
					pDC->Ellipse(x3, y3, x1, y3 + c);
				}
			}
			else
			{
				if (a > d)
				{
					pDC->Ellipse(x3, y3, x3 - d, y1);
				}
				else
				{
					pDC->Ellipse(x3, y3, x1, y3 + a);
				}
			}
		}
	}
}

Hinhtron::Hinhtron(void)
{
}
Hinhtron::~Hinhtron(void)
{
}
