#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Muzafarov
{
public:
	Muzafarov();
	virtual void copy(vector <Muzafarov*>& v);
	Muzafarov(const Muzafarov& obj);
	virtual void print() = 0;
	virtual ~Muzafarov();
};