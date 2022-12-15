#include "Muzafarov_1.h"

Muzafarov_1::Muzafarov_1() {
	a = new int;
	*a = 123;
	ch = 'M';
}
Muzafarov_1::Muzafarov_1(const Muzafarov_1& obj) : Muzafarov(obj) {
	this->a = new int;
	*a = *obj.a;
	this->ch = obj.ch;
}
void Muzafarov_1::print() {
	cout << ch << ' ' << *a << endl;
}
Muzafarov_1:: ~Muzafarov_1() {
	delete a;
}
void Muzafarov_1::copy(vector<Muzafarov*>& v) {}
