#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Muzafarov
{
public:
    virtual void print() = 0;
    virtual Muzafarov* copy() = 0;
};

class Muzafarov_child_1 : public Muzafarov
{

public:
    string* name;

    Muzafarov_child_1()
    {
        name = new string("");
        string s;
        cout << "Input your name: ";
        getline(cin, s);
        name->append(s);
    }

    void print()
    {
        cout << *name << endl;
    }

    ~Muzafarov_child_1()
    {
        delete name;
    }

    Muzafarov_child_1(const Muzafarov_child_1& o) {
        name = new string(*o.name);
    }

    virtual Muzafarov_child_1* copy() {
        return new Muzafarov_child_1(*this);
    }

};

class Muzafarov_child_2 : public Muzafarov
{
public:
    int* arr;
    int n;

    Muzafarov_child_2()
    {
        arr = new int[10];

        for (int i = 0; i < 10; i++)
        {
            arr[i] = rand() % 100;
        }
    }

    void print()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "arr[" << i << ']' << arr[i] << endl;
        }

        cout << endl;
    }

    ~Muzafarov_child_2()
    {
        delete[] arr;
    }

    Muzafarov_child_2(const Muzafarov_child_2& o) {
        arr = new int(*o.arr);
    }

    virtual Muzafarov_child_2* copy() {
        return new Muzafarov_child_2(*this);
    }
};

class Muzafarov_child_3 : public Muzafarov
{
public:
    float* m_const;

    Muzafarov_child_3()
    {
        m_const = new float[2];
        m_const[0] = 3.1415926;
        m_const[1] = 2.7182818;
    }

    void print()
    {
        int i = 0;
        while (i < 2)
        {
            switch (i)
            {
            case 1:
                cout << "e = " << m_const[i] << " ";
                break;

            case 0:
                cout << "pi = " << m_const[i] << " ";
                break;

            default:
                break;
            }
            i++;
        }

        cout << endl;
    }

    ~Muzafarov_child_3()
    {
        delete[] m_const;
    }
    Muzafarov_child_3(const Muzafarov_child_3& o) {
        m_const = new float(*o.m_const);
    }
    virtual Muzafarov_child_3* copy() {
        return new Muzafarov_child_3(*this);
    }
};


int main() {
    srand(time(NULL));

    vector<Muzafarov*> data1;

    for (int i = 0; i < 6; i++) {

        if (i % 3 == 0)
            data1.push_back(new Muzafarov_child_1);

        if (i % 3 == 1)
            data1.push_back(new Muzafarov_child_2);

        if (i % 3 == 2)
            data1.push_back(new Muzafarov_child_3);
    }



    for (int i = 0; i < 6; i++) {
        data1[i]->print();
    }

    vector<Muzafarov*> data2;

    for (vector <Muzafarov*>::iterator it = data1.begin(); it != data1.end(); ++it) {
        Muzafarov* new_obj = (*it)->copy();
        data2.insert(data2.end(), new_obj);
    }


    for (int i = 0; i < 6; i++)
    {
        delete data1[i];
    }


    for (int i = 0; i < 6; i++)
    {
        delete data2[i];
    }

    return 0;
}