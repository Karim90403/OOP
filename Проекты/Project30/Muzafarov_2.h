#pragma once
#include "Muzafarov.h"
#include "Muzafarov_1.h"

class Muzafarov_2 : public Muzafarov_1
{
	int* a;
	char ch;
public:
	Muzafarov_2();
	Muzafarov_2(const Muzafarov_2& obj);
	void print();
	void copy(vector<Muzafarov*>& v);
	~Muzafarov_2();
};

