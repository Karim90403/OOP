#pragma once
#include "Muzafarov_2.h"
template <class T>

class DB :public list<Muzafarov*>
{
public:
    DB() {}

    DB(const DB& obj)
    {
        DB<Muzafarov*> ::const_iterator it = obj.begin();
        for (; it != obj.end(); it++) {
            Muzafarov* new_obj = ((*it)->copy());
            (*this).push_back(new_obj);
        }
    }

    void print() {
        cout << "-----------------" << endl;
        DB<Muzafarov*> ::iterator it;
        for (it = (*this).begin(); it != (*this).end(); it++)
            (*it)->print();
        cout << "-----------------" << endl;
    }

    void replace(DB& obj)
    {
        DB<Muzafarov*>::iterator it;
        for (it = obj.begin(); it != obj.end(); it++)
            delete* it;
        obj.clear();

        for (it = (*this).begin(); it != (*this).end(); it++)
        {
            Muzafarov* new_obj = (*it)->copy();
            obj.push_back(new_obj);
        }
    }

    DB& operator= (const DB& obj)
    {
        if (this == &obj) return *this;

        DB<Muzafarov*>::iterator it;
        for (it = (*this).begin(); it != (*this).end(); it++)
            delete* it;
        (*this).clear();

        DB<Muzafarov*> ::const_iterator с_it;

        for (с_it = obj.begin(); с_it != obj.end(); с_it++)
            (*с_it)->app(*this);

        replace(const_cast<DB&>(obj));

        return *this;
    }

    ~DB()
    {
        DB<Muzafarov*> ::iterator it;
        for (it = (*this).begin(); it != (*this).end(); it++)
            delete* it;
        (*this).clear();
    }
};