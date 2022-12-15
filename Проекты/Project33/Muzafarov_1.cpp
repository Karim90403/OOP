#include "Muzafarov_1.h"

Muzafarov_1::Muzafarov_1() {
    type = new string(typeid(Muzafarov_1).name());
}

Muzafarov_1::Muzafarov_1(const Muzafarov_1& obj) :Muzafarov(obj) { type = new string; *type = *obj.type; }

void Muzafarov_1::app(list<Muzafarov*>& l) {}

Muzafarov* Muzafarov_1::copy() {
    return new Muzafarov_1(*this);
}

Muzafarov_1:: ~Muzafarov_1() { delete type;  }
