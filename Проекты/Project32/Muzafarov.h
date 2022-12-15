#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Muzafarov
{
public:
    int i = 0;
    list <string*>* l = new list<string*>;
    Muzafarov();
    Muzafarov(const Muzafarov& obj);
    virtual Muzafarov* copy();
    virtual void replace();
    virtual void print();
    virtual ~Muzafarov();
};