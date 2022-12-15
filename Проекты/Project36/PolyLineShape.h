#pragma once
#include "LineShape.h"

class PolyLineShape : public Shape
{
	vector<Koordinates> v;
	int min_x, min_y, max_x, max_y, centre_x, centre_y;
	string* class_name;
public:
	PolyLineShape();
	PolyLineShape(vector <int>& x, vector <int>& y);
	void print();
	~PolyLineShape();
};

