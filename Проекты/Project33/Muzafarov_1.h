#pragma once
#include "Muzafarov.h"

class Muzafarov_1 : public Muzafarov
{
    string* type;
public:
    Muzafarov_1();
    Muzafarov_1(const Muzafarov_1& obj);
    virtual Muzafarov* copy();
    void app(list<Muzafarov*>& l);
    virtual ~Muzafarov_1();
};

