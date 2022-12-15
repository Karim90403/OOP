#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Muzafarov
{
    string* type;
public:
    Muzafarov();
    Muzafarov(const Muzafarov& obj);
    virtual Muzafarov* copy();
    virtual void app(list<Muzafarov*>& l);
    virtual void print();
    virtual ~Muzafarov();
};

