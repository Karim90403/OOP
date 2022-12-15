#include <iostream>
#include <list>
#include <vector>

using namespace std;


struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};


Leaks l_;


class Muzafarov
{
public:

    virtual ~Muzafarov() {}
    Muzafarov() {}
    Muzafarov(const Muzafarov& obj) {}
    virtual Muzafarov* copy() = 0;
    virtual void print() {};
    virtual void Replace() {};

};

class Muzafarov_1 :public Muzafarov
{
public:

    char str[10];
    list <int*>* l = new list<int*>;

    Muzafarov_1()
    {
        for (int i = 0; i < 10; i++)
            l->push_back(new int(i));

        for (int i = 0; i < 10; i++)
            str[i] = char(int('0') + i);
    }

    Muzafarov_1(const Muzafarov_1& obj) : Muzafarov(obj)
    {
        for (list<int*>::iterator it = obj.l->begin(); it != obj.l->end(); ++it) {
            int* i = new int(**it);
            (*l).push_back(i);
        }

        for (int i = 0; i < 10; i++)
            str[i] = obj.str[i];
    }

    virtual Muzafarov* copy() {
        return new Muzafarov_1(*this);
    }

    void Replace()
    {
        list<int*> ::iterator it;
        for (it = (*l).begin(); it != (*l).end(); it++)
            **it = 3;

        for (int i = 0; i < 10; i++)
            str[i] = 'A' + i;
    }

    virtual void print()
    {
        cout << "M1" << endl;

        cout << "list: ";
        list<int*> ::iterator it;
        for (it = (*l).begin(); it != (*l).end(); it++)
            cout << **it << " ";

        cout << endl << "str: ";
        for (int i = 0; i < 10; i++)
            cout << str[i];

        cout << endl << "---------------" << endl;
    }

    virtual ~Muzafarov_1()
    {
        list<int*> ::iterator it;
        for (it = (*l).begin(); it != (*l).end(); it++)
            delete* it;

        delete l;
    }
};

class Muzafarov_2 :public Muzafarov_1
{

public:
    float* f = new float(0.1);

    Muzafarov_2() {}

    Muzafarov_2(const Muzafarov_2& obj) :Muzafarov_1(obj) {}

    void Replace() {
        list<int*> ::iterator it;
        for (it = (*l).begin(); it != (*l).end(); it++)
            **it = 3;

        for (int i = 0; i < 10; i++)
            str[i] = 'A' + i;
        *f = 0.6;
    }

    virtual Muzafarov* copy() {
        return new Muzafarov_2(*this);
    }

    void print() {
        cout << "M2" << endl;

        cout << "list: ";
        list<int*> ::iterator it;
        for (it = (*l).begin(); it != (*l).end(); it++)
            cout << **it << " ";

        cout << endl << "str: ";
        for (int i = 0; i < 10; i++)
            cout << str[i];

        cout << endl << "f = " << *f << endl;
    }

    virtual ~Muzafarov_2() {
        delete f;
    }
};

class Muzafarov_3 :public Muzafarov_2
{
public:
    double* d = new double(0.2);

    Muzafarov_3() {}

    Muzafarov_3(const Muzafarov_3& obj) :Muzafarov_2(obj) {}

    void Replace() {
        list<int*> ::iterator it;
        for (it = (*l).begin(); it != (*l).end(); it++)
            **it = 3;

        for (int i = 0; i < 10; i++)
            str[i] = 'A' + i;
        *f = 0.6;
        *d = 0.7;
    }

    virtual Muzafarov* copy() {
        return new Muzafarov_3(*this);
    }

    void print() {
        cout << "M3" << endl;

        cout << "list: ";
        list<int*> ::iterator it;
        for (it = (*l).begin(); it != (*l).end(); it++)
            cout << **it << " ";

        cout << endl << "str: ";
        for (int i = 0; i < 10; i++)
            cout << str[i];

        cout << endl << "f = " << *f << endl;
        cout << "d = " << *d << endl;
    }

    ~Muzafarov_3() {
        delete d;
    }
};

class DB
{
    friend void DeleteVector(DB& db);

private:
    list<Muzafarov*> db_l;

public:
    DB() {}

    DB(DB& obj)
    {
        list<Muzafarov*> ::iterator it;

        for (it = obj.db_l.begin(); it != obj.db_l.end(); it++)
        {
            Muzafarov* new_obj = (*it)->copy();
            db_l.insert(db_l.end(), new_obj);
        }
    }

    void print_db()
    {
        cout << "---------------" << endl;
        list<Muzafarov*> ::iterator it;
        for (it = db_l.begin(); it != db_l.end(); it++)
            (*it)->print();
        cout << "---------------" << endl;
    }

    void Push(Muzafarov* b)
    {
        db_l.push_back(b);
    }

    void CopyData(DB& obj)
    {
        list<Muzafarov*> ::iterator it;

        for (it = obj.db_l.begin(); it != obj.db_l.end(); it++)
        {
            Muzafarov* new_obj = (*it)->copy();
            db_l.insert(db_l.end(), new_obj);
        }
    }

    void DeleteData()
    {
        list<Muzafarov*> ::iterator it;
        for (it = db_l.begin(); it != db_l.end(); it++)
            delete* it;
        db_l.clear();
    }

    DB& operator= (DB& obj)
    {
        if (this == &obj) return *this;

        this->DeleteData();
        CopyData(obj);

        return *this;
    }

    void Change()
    {
        for (list <Muzafarov*>::iterator it = db_l.begin(); it != db_l.end(); it++)
        {
            (*it)->Replace();
        }
    }
    ~DB()
    {
        list<Muzafarov*> ::iterator it;
        for (it = db_l.begin(); it != db_l.end(); it++)
            delete* it;
        db_l.clear();
    }
};

int main()
{
    DB db1, db2;

    db1.Push(new Muzafarov_1());
    db1.Push(new Muzafarov_2());
    db1.Push(new Muzafarov_3());

    for (int i = 0; i < 2; i++)
    {
        db2.Push(new Muzafarov_1());
        db2.Push(new Muzafarov_2());
        db2.Push(new Muzafarov_3());
    }

    db1.Change();
    db2 = db1;

    cout << "db1" << endl; db1.print_db(); cout << endl;
    cout << "db2" << endl; db2.print_db();
    return 0;
}
