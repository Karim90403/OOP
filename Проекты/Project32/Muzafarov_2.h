#pragma once
#include "Muzafarov_1.h"

class Muzafarov_2 :public Muzafarov_1
{
public:
    double* d;
    list <string*>* manystr = new list<string*>;

    Muzafarov_2();
    Muzafarov_2(const Muzafarov_2& obj);
    void replace();
    virtual Muzafarov* copy();
    void print();
    ~Muzafarov_2();
};
