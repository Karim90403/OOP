#include "Muzafarov.h"

Muzafarov::Muzafarov() {
    type = new string(typeid(Muzafarov).name());

}

Muzafarov::Muzafarov(const Muzafarov& obj) {
    type = new string; *type = *obj.type;
}

Muzafarov* Muzafarov::copy() {
    return new Muzafarov(*this);
}

void Muzafarov::app(list<Muzafarov*>& l) {}

void Muzafarov::print()
{
    cout << *type << endl;
}

Muzafarov:: ~Muzafarov()
{
    delete type;
}
