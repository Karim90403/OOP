#pragma once
#include "Karim.h"

template <class T>

class DB :public vector<T>
{
public:
    DB() {}
    ~DB()
    {
       DB<Muzafarov*>::iterator it;

        for (it = (*this).begin(); it != (*this).end(); it++)
            delete *it;

        (*this).clear();
    }
    DB(const DB& obj)
    {
        DB<Muzafarov*> ::const_iterator it = obj.begin();
        for (; it != obj.end(); it++) {
            Muzafarov* new_obj = ((*it)->copy());
            this->push_back(new_obj);
        }
    }

    void copyData(const DB& obj)
    {
        DB<Muzafarov*> ::const_iterator it;
        for (it = obj.begin(); it != obj.end(); it++) {
            Muzafarov* new_obj = (*it)->copy();
            this->insert(this->end(), new_obj);
        }
    }

    void deleteData()
    {
        DB<Muzafarov*>::iterator it;
        for (it = (*this).begin(); it != (*this).end(); it++)
            delete* it;
        (*this).clear();
    }

    DB& operator= (const DB& obj)
    {
        if (this == &obj) return *this;

        this->deleteData();
        copyData(obj);

        return *this;
    }

    void print()
    {
        for (int i = 0; i < (*this).size(); i++)
            (*this)[i] -> print();
    }

    void cleanData()
    {
        int countMuzafarov = 0, countKarim = 0;
        for (int i = 0; i < (*this).size(); i++) {
            if ((*this)[i]->checkClass() == "Muzafarov" && countMuzafarov == 0)
            {
                countMuzafarov++;
            }
            else if ((*this)[i]->checkClass() == "Muzafarov" && countMuzafarov > 0)
            {
                delete (*this)[i];
                this->erase(this->begin() + i);
                if (i > 0) { i--; }
            }
        }
        for (int i = 0; i < (*this).size(); i++) {
            if ((*this)[i]->checkClass() == "Karim" && countKarim == 0)
            {
                countKarim++;
            }
            else if ((*this)[i]->checkClass() == "Karim" && countKarim > 0)
            {
                delete (*this)[i];
                this->erase(this->begin() + i);
                if (i > 0) { i--; }
            }
        }

        if ((*this)[0]->checkClass() == "Karim")
            swap((*this)[0], (*this)[1]);

    }

    void fill(vector<wstring>& v, int end)
    {
        int countKarim = 0, countMuzafarov = 0;
        for (int i = 0; i < 6; i++)
        {
            if (rand() % 10 > i)
            {
                (*this).push_back(new Muzafarov);
                (*this)[i]->push(v, 0, end);
                countMuzafarov++;
            }
            else
            {
                (*this).push_back(new Karim);
                (*this)[i]->push(v, end, v.size());
                countKarim++;
            }
        }

        if (countMuzafarov == 0)
        {
            (*this).push_back(new Muzafarov);
            (*this).push_back(new Karim);
            (*this)[(*this).size()]->push(v, 0, end);
        }
        else if (countKarim == 0)
        {
            (*this).push_back(new Karim);
            (*this)[(*this).size()]->push(v, 0, end);
        }
    }
};

