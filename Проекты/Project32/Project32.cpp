#include "Muzafarov.h"
#include "Muzafarov_1.h"
#include "Muzafarov_2.h"
#include "DB.h"

struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};

Leaks l_;

int main()
{
    DB<Muzafarov*> db1;

    db1.push_back(new Muzafarov);
    db1.push_back(new Muzafarov_1);
    db1.push_back(new Muzafarov_2);

    db1.change();
    DB<Muzafarov*> db2 = db1;
    
    //db1 = db2;

    cout << "db1" << endl; db1.print(); cout << endl;
    cout << "db2" << endl; db2.print();
    return 0;
}