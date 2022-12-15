#pragma once
#include "Koordinates.h"

class Shape
{
public:
	vector<Koordinates> v;
	Shape();
	virtual ~Shape();
	virtual void print(HDC* hdc, int sx, int sy);
};

