#include "Karim.h"

Muzafarov* Karim::copy() {
	return new Karim(*this); 
}

string Karim::checkClass()
{
	return "Karim";
}