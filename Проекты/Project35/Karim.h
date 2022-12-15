#pragma once
#include "Muzafarov.h"
class Karim: public Muzafarov
{
public:
	Karim() {}
	~Karim() {}
	virtual Muzafarov* copy();
	string checkClass();
};
