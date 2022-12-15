#pragma once
#include "Muzafarov.h"
#include <string>
class Muzafarov_1 : public Muzafarov
{
	int* a;
	char ch;
public:
	Muzafarov_1();
	Muzafarov_1(const Muzafarov_1& obj);
	void print();
	void copy(vector<Muzafarov*>& v);
	virtual ~Muzafarov_1();
};