#include "Muzafarov_2.h"

Muzafarov_2::Muzafarov_2() {
    type = new string(typeid(Muzafarov_2).name());
}

Muzafarov_2::Muzafarov_2(const Muzafarov_2& obj) :Muzafarov_1(obj) {
    type = new string; *type = *obj.type;
}

void Muzafarov_2::app(list<Muzafarov*>& obj) {
    Muzafarov* new_obj = (this)->copy();
    obj.push_back(new_obj);
}

Muzafarov* Muzafarov_2::copy() {
    return new Muzafarov_2(*this);
}

Muzafarov_2:: ~Muzafarov_2() { delete type;  }
