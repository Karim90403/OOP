#include "Muzafarov_2.h"

Muzafarov_2::Muzafarov_2() {
    i++;
    d = new double;
    *d = 0.2;

    for (int i = 0; i < 10; i++)
        manystr->push_back(new string("9"));
}

Muzafarov_2::Muzafarov_2(const Muzafarov_2& obj) :Muzafarov_1(obj) {
    d = new double;
    *d = *(obj.d);
    list<string*>::iterator it;
    for (it = obj.manystr->begin(); it != obj.manystr->end(); ++it) {
        string* new_i = new string(**it);
        manystr->push_back(new_i);
    }
}

void Muzafarov_2::replace() {
    Muzafarov_1::replace();
    *d = 0.3;

    list<string*> ::iterator it;
    for (it = manystr->begin(); it != manystr->end(); it++)
        **it = "C";
}

Muzafarov* Muzafarov_2::copy() {
    return new Muzafarov_2(*this);
}

void Muzafarov_2::print() {
    Muzafarov_1::print();
    cout << "d = " << *d << endl;

    cout << "manystr: ";
    list<string*> ::iterator it;
    for (it = manystr->begin(); it != manystr->end(); it++)
        cout << **it << " ";
    cout << endl;
}

Muzafarov_2::~Muzafarov_2() { 
    delete d;

    list<string*> ::iterator it;
    for (it = (*manystr).begin(); it != (*manystr).end(); it++)
        delete* it;

    delete manystr;
}