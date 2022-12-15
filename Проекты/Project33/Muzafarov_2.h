#pragma once
#include "Muzafarov_1.h"
class Muzafarov_2 : public Muzafarov_1
{
    string* type;
public:
    Muzafarov_2();
    Muzafarov_2(const Muzafarov_2& obj);
    virtual Muzafarov* copy();
    void app(list<Muzafarov*>& l);
    ~Muzafarov_2();
};

