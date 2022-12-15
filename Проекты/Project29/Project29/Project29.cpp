#include <iostream>
#include <vector>

using namespace std;

struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};

class Muzafarov
{
public:

    virtual ~Muzafarov() {}
    Muzafarov() {}
    Muzafarov(const Muzafarov& obj) {}
    virtual Muzafarov* copy() = 0;
    virtual void print() = 0;
    virtual void Change() {}

};

class Muzafarov_1 :public Muzafarov
{
    friend void change() {}
public:

    int* a = new int(33);
    Muzafarov_1() {}

    Muzafarov_1(const Muzafarov_1& obj) : Muzafarov(obj)
    {
        *a = *obj.a;
    }

    virtual Muzafarov_1* copy()
    {
        return new Muzafarov_1(*this);
    }

    void Change()
    {
        *a = 55;
    }

    void print()
    {
        cout << "M1 " << *a << endl;
    }

    ~Muzafarov_1()
    {
        delete a;
    }
};

class Muzafarov_2 :public Muzafarov_1
{
public:
    float* f = new float(0.001);

    Muzafarov_2() {}

    Muzafarov_2(const Muzafarov_2& obj) :Muzafarov_1(obj)
    {
        *f = *obj.f;
    }

    void Change() {}

    Muzafarov_2* copy()
    {
        return new Muzafarov_2(*this);
    }

    void print()
    {
        cout << "M2 " << *a << "    " << *f << endl;
    }

    ~Muzafarov_2()
    {
        delete f;
    }
};

class DB
{
    friend void change(DB&);

private:
    vector<Muzafarov*> v;

public:
    DB() {}

    DB(const DB& obj)
    {
        for (int i = 0; i < obj.v.size(); i++)
        {
            v.push_back(obj.v[i]->copy());
        }
    }

    void print()
    {
        cout << "--------------" << endl;
        for (int i = 0; i < v.size(); i++)
        {
            v[i]->print();
        }
        cout << "--------------" << endl;
    }
 
    void DeleteVector()
    {
        for (int i = 0; i < v.size(); i++)
        {
            delete v[i];
        }
    }

    void Append(Muzafarov_1* kl)
    {
        v.push_back(kl);
    }
    ~DB() {}
};

void change(DB& db)
{
    for (int i = 0; i < db.v.size(); i++)
    {
        db.v[i]->Change();
    }
}

Leaks _l;

int main()
{
    Muzafarov_1* b1 = new Muzafarov_1;
    Muzafarov_1* b2 = new Muzafarov_1;
    Muzafarov_2* b3 = new Muzafarov_2;
    Muzafarov_2* b4 = new Muzafarov_2;

    DB* db1 = new DB;

    db1->Append(b1);
    db1->Append(b2);
    db1->Append(b3);
    db1->Append(b4);
    cout << "DB1 " << endl;
    db1->print();
    cout << endl;

    change(*db1);
    cout << "change DB1 " << endl;
    db1->print();
    cout << endl;

    DB db2(*db1), db3;
    cout << "DB2 " << endl;
    db2.print();
    cout << endl;
    db1->DeleteVector();
    delete db1;

    db3 = db2;
    cout << "DB3 " << endl;
    db3.print();
}
