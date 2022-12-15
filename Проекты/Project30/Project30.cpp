#include "Muzafarov.h"
#include "Muzafarov_1.h"
#include "Muzafarov_2.h"
#include "DB.h"

struct Leaks {
	~Leaks() {
		_CrtDumpMemoryLeaks();
	}
};
Leaks _l;

void Create(DB& db)
{
	Muzafarov* obj1 = new Muzafarov_1();
	Muzafarov* obj2 = new Muzafarov_2();
	Muzafarov* obj3 = new Muzafarov_1();
	Muzafarov* obj4 = new Muzafarov_2();
	db.push(obj1);
	db.push(obj2);
	db.push(obj3);
	db.push(obj4);
}

int main()
{
	DB db1;
	Create(db1);
	db1.print();
	DB db2 = db1;
	db2.print();
	db1 = db2;
	db1.print();
	new char;
}