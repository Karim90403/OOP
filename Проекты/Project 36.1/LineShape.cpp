#include "LineShape.h"

LineShape::LineShape() {
}

LineShape::LineShape(vector<int>& x, vector<int>& y)
{
	for (int i = 0; i < x.size(); i++) {
		v.push_back(
			Koordinates(x[i], y[i]));
	}

	min_x = x[0];

	for (int i = 1; i < x.size(); i++)
	{
		if (min_x > x[i])
			min_x = x[i];
	}

	min_y = y[0];

	for (int i = 1; i < x.size(); i++)
	{
		if (min_y > y[i])
			min_y = y[i];
	}

	max_x = x[0];

	for (int i = 1; i < x.size(); i++)
	{
		if (max_x < x[i])
			max_x = x[i];
	}

	max_y = y[0];

	for (int i = 1; i < x.size(); i++)
	{
		if (max_y < y[i])
			max_y = y[i];
	}
	int sx = 0, sy = 0;


	for (int i = 0; i < v.size(); i++) {
		sx += v[i].x;
		sy += v[i].y;
	}

	centre_x = sx / v.size();
	centre_y = sy / v.size();

	class_name = new string(typeid(LineShape).name());

}


void LineShape::print(HDC* hdc, int sx, int sy)
{
	if (v[0].x/sx > 1) {

		centre_x = (centre_x * sx) / 10000;
		centre_y = (centre_y * sy) / 10000;

		int px = (sx / 2) - centre_x,
			py = (sy / 2) - centre_y;

		for (int i = 0; i < v.size(); i++) {
			v[i].x = (v[i].x * sx) / 10000 + px;
			v[i].y = (v[i].y * sy) / 10000 + py;
		}
	}

	for (int i = 0; i < v.size() - 1; i++) {
		MoveToEx(*hdc, v[i].x, v[i].y, NULL);
		LineTo(*hdc, v[i + 1].x, v[i + 1].y);
	}
}


LineShape::~LineShape() {
	delete class_name;
}
