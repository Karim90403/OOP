#include "Muzafarov.h"
#include "Muzafarov_1.h"
#include "Muzafarov_2.h"
#include "DB.h"

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
};

Leaks l_;

DB<Muzafarov*> db1, db2;

int main()
{
	for (int i = 0; i < 2; i++)
	{
		db1.push_back(new Muzafarov);
		db1.push_back(new Muzafarov_1);
		db1.push_back(new Muzafarov_2);
	}

	db2 = db1;

	cout << "db1" << endl; db1.print();
	cout << "db2" << endl; db2.print();
}
