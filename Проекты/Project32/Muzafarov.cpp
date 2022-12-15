#include "Muzafarov.h"

Muzafarov::Muzafarov() {
    i++;
    for (int i = 0; i < 10; i++)
        l->push_back(new string("A"));
}

Muzafarov::Muzafarov(const Muzafarov& obj) {
    list<string*>::iterator it;
    for (it = obj.l->begin(); it != obj.l->end(); ++it) {
        string* new_i = new string(**it);
        l->push_back(new_i);
    }
    i = obj.i;
}

Muzafarov* Muzafarov::copy() {
    return new Muzafarov(*this);
}

void Muzafarov::replace()
{
    list<string*> ::iterator it;
    for (it = l->begin(); it != l->end(); it++)
        **it = "B";
}

void Muzafarov::print()
{
    cout << 'M' << i << endl;
    cout << "string list: ";
    list<string*> ::iterator it;
    for (it = (*l).begin(); it != (*l).end(); it++)
        cout << **it << " ";

    cout << endl;
}

Muzafarov:: ~Muzafarov()
{
    list<string*> ::iterator it;
    for (it = (*l).begin(); it != (*l).end(); it++)
        delete* it;

    delete l;
}
