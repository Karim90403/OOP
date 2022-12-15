#pragma once
#include "Muzafarov_2.h"
template <class T>

class DB : public list<T>
{
public:
    DB() {}

    DB(const DB& obj)
    {
        DB<Muzafarov*> ::const_iterator it;
        for (it = obj.begin(); it != obj.end(); it++) {
            Muzafarov* new_obj = (*it)->copy();
            this->insert(this->end(), new_obj);
        }
    }

    void print() {
        cout << "--------------------------------------------------" << endl;
        DB<Muzafarov*> ::iterator it;
        for (it = this->begin(); it != this->end(); it++)
            (*it)->print();
        cout << "--------------------------------------------------" << endl;
    }


    void copyData(const DB& obj)
    {
        DB<Muzafarov*> ::iterator it;
        for (it = obj.begin(); it != obj.end(); it++) {
            Muzafarov* new_obj = (*it)->copy();
            this->insert(this->end(), new_obj);
        }
    }

    void deleteData()
    {
        DB<Muzafarov*> ::iterator it;
        for (it = this->begin(); it != this->end(); it++)
            delete* it;
        this->clear();
    }

    DB& operator= (const DB& obj)
    {
        if (this == &obj) return *this;

        this->deleteData();
        copyData(obj);

        return *this;
    }


    void change()
    {
        DB <Muzafarov*>::iterator it;
        for (it = this->begin(); it != this->end(); it++)
            (*it)->replace();
    }
    ~DB()
    {
        DB<Muzafarov*> ::iterator it;
        for (it = this->begin(); it != this->end(); it++)
            delete* it;
        this->clear();
    }
};
