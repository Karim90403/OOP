#include "Muzafarov_2.h"

Muzafarov_2::Muzafarov_2() {
	a = new int;
	*a = 456;
	ch = 'm';
}
Muzafarov_2::Muzafarov_2(const Muzafarov_2& obj) : Muzafarov_1(obj) {
	this->a = new int;
	*a = *obj.a;
	ch = obj.ch;
}
void Muzafarov_2::print() {
	cout << ch << ' ' << *a << endl;
}
Muzafarov_2:: ~Muzafarov_2() {
	delete a;
}
void Muzafarov_2::copy(vector<Muzafarov*>& v) {
	v.push_back(new Muzafarov_2(*this));
}