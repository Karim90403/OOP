#pragma once
#include "Shape.h"

class LineShape : public Shape
{

	string* class_name;
	int size, min_x = 0, min_y = 0, max_x = 0, max_y = 0, centre_x = 0, centre_y = 0;
public:
	LineShape();
	LineShape(vector <int>& x, vector <int>& y);
	void print(HDC* hdc, int sx, int sy);
	~LineShape();
};