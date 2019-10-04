#include "StdAfx.h"
#include "Dongxu.h"
#include "math.h"


Dongxu::Dongxu(void)
{
}



void Dongxu::thietlap(int mx1, int my1, int mx3, int my3)//dinh nghia phuong thuc thiet lap toa do
{
	x1 = mx1;
	y1 = my1;
	x3 = mx3;
	y3 = my3;
}
float Dongxu::dientich()
{
	float kq , r;
	r = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1)) / 2;
	kq = 3.14 * r* r;
	return kq;
}
float Dongxu::chuvi()
{
	float kq = 0, r;
	r = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1) / 2);
	kq = 3.14 * r * 2;
	return kq;
}

Dongxu::~Dongxu(void)
{
}
