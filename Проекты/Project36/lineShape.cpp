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

	class_name = new string(typeid(LineShape).name());
}


void LineShape::print()
{
	cout << *class_name << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << "(" << v[i].x << ":" << v[i].y << ")" << endl;
	}
	cout << "Max Koord X: " << max_x << endl;
	cout << "Min Koord X: " << min_x << endl;
	cout << "Max Koord Y: " << max_y << endl;
	cout << "Min Koord Y: " << min_y << endl;
	cout << "Figure center: " << "(" << centre_x << ":" << centre_y << ")" << endl;
	cout << endl;
}


LineShape::~LineShape() {
	print();
	delete class_name;
}
