#pragma once
#include "Muzafarov.h"
class Muzafarov_1 :public Muzafarov
{
public:
    list <float>* f = new list<float>;

    Muzafarov_1();
    Muzafarov_1(const Muzafarov_1& obj);
    virtual Muzafarov* copy();
    virtual void replace();
    virtual void print();
    virtual ~Muzafarov_1();
};
