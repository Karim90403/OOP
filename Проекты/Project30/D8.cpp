#include "DB.h"

DB::DB() {}

DB::~DB()
{
	for (int i = 0; i < v.size(); i++)
		delete v[i];
}

void DB::append(Muzafarov* v)
{
	this->v.push_back(v);
}


DB::DB(const DB& obj)
{
	for (int i = 0; i < obj.v.size(); i++)
		obj.v[i]->copy(v);
}

void DB::print()
{
	for (int i = 0; i < v.size(); i++)
		v[i]->print();

	cout << "size = " << v.size() << endl;
}

DB& DB::operator=(const DB& obj)
{

	if (this == &obj)return *this;

	if (v.size() > 0)
	{
		for (int i = 0; i < v.size(); i++)
			delete this->v[i];
	}

	v.clear();

	for (int i = 0; i < obj.v.size(); i++)
		obj.v[i]->copy(v);

	return *this;
}