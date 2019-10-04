#pragma once
#include"Hinhtron.h"
class Dongxu:public Hinhtron
{
private: 
	float x1, y1, x3, y3;

public:
	Dongxu(void);

	void thietlap(int mx1, int my1, int mx3, int my3);
	float chuvi();
	float dientich();
	~Dongxu(void);
};

