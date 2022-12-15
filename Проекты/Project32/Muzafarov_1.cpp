#include "Muzafarov_1.h"

Muzafarov_1::Muzafarov_1() {
    for (int i = 0; i < 10; i++)
        f->push_back(i + i / 10.);
    i++;
}

Muzafarov_1::Muzafarov_1(const Muzafarov_1& obj) :Muzafarov(obj) {
    list<float>::iterator it;
    for (it = obj.f->begin(); it != obj.f->end(); ++it) {
        float new_i = *it;
        f->push_back(new_i);
    }
}

void Muzafarov_1::replace() {

    Muzafarov::replace();
    list<float> ::iterator it;
    for (it = (*f).begin(); it != (*f).end(); it++)
        *it -= 0.1;
}

Muzafarov* Muzafarov_1::copy() {
    return new Muzafarov_1(*this);
}

void Muzafarov_1::print() {
    Muzafarov::print();
    list<float> ::iterator it;
    cout << "float list: ";
    for (it = f->begin(); it != f->end(); it++)
        cout << *it << " ";

    cout << endl;
}

Muzafarov_1:: ~Muzafarov_1() {
    delete f;
}
