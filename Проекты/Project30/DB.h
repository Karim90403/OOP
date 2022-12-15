#pragma once
#include "Muzafarov.h"
#include "Muzafarov_1.h"
#include "Muzafarov_2.h"
class DB
{
	vector<Muzafarov*> v;
public:
	DB();
	~DB();
	DB(const DB& new_obj);
	void push(Muzafarov* v);
	void print();
	DB& operator = (const DB& new_ob);
};