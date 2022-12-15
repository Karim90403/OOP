#include<iostream>
#include<list>

using namespace std;

struct Leaks
{
	~Leaks()
	{
		_CrtDumpMemoryLeaks();
	}
};
Leaks l;

class Muzafarov
{
public:
	Muzafarov() {};
	virtual ~Muzafarov() {}
	virtual void Change() {}
	virtual void print() {}
	virtual void Copy(list<Muzafarov*>& l) = 0;
};

class Muzafarov_1 : public Muzafarov
{
public:
	list<int*>* l = new list<int*>;
	char str[10];

	Muzafarov_1()
	{
		l->push_back(new int(10));
		for (int i = 0; i < 10; i++) {
			str[i] = '0' + i;
		}
	}
	void Change()
	{
		for (list <int*>::iterator it = l->begin(); it != l->end(); it++)
		{
			delete (*it);
		}
		delete l;

		l = new list<int*>;
		l->push_back(new int(2));
		for (int i = 0; i < 10; i++)
			str[i] = 'A' + i;
	}
	~Muzafarov_1()
	{
		for (list <int*>::iterator it = l->begin(); it != l->end(); it++)
		{
			delete (*it);
		}
		delete l;
	}
	Muzafarov_1(const Muzafarov_1& obj)
	{
		for (list <int*>::iterator it = l->begin(); it != l->end(); it++) {
			delete (*it);
		}
		delete l;
		l = new list<int*>;
		for (list<int*>::iterator it = obj.l->begin(); it != obj.l->end(); ++it) {
			int* i = new int;
			*i = 26;
			(*l).push_back(i);
		}
		for (int i = 0; i < 10; i++)
			str[i] = obj.str[i];
	}
	void print()
	{
		cout << "M1" << endl;

		cout << "list: ";
		list<int*> ::iterator it;
		for (it = (*l).begin(); it != (*l).end(); it++)
			cout << **it << " ";

		cout << endl << "Str: ";
		for (int i = 0; i < 10; i++)
			cout << str[i];

		cout << endl << "---------------" << endl;
	}

	virtual void Copy(list<Muzafarov*>& L)
	{
		L.push_back(new Muzafarov_1(*this));
	}

};

class Muzafarov_2 : public Muzafarov_1
{
public:
	float* f;
	Muzafarov_2()
	{
		f = new float;
		*f = 1.23;
	}
	void Change()
	{
		delete f;
		f = new float;
		*f = 4.56;
	}
	~Muzafarov_2()
	{
		delete f;
	}
	Muzafarov_2(const Muzafarov_2& obj) :Muzafarov_1(obj)
	{

	}
	virtual void Copy(list<Muzafarov*>& l) {}

	void print()
	{
		cout << "M2" << endl;

		cout << "list: ";
		list<int*> ::iterator it;
		for (it = (*l).begin(); it != (*l).end(); it++)
			cout << **it << " ";

		cout << endl << "Str: ";
		for (int i = 0; i < 10; i++)
			cout << str[i];

		cout << endl << "f = " << *f << endl;
	}
};

class Muzafarov_3 : public Muzafarov_2
{
public:
	double* d;
	Muzafarov_3()
	{
		d = new double;
		*d = 7.89;
	}
	void Change()
	{
		delete d;
		d = new double;
		*d = 1.01;
	}
	~Muzafarov_3()
	{
		delete d;
	}

	Muzafarov_3(const Muzafarov_3& obj) :Muzafarov_2(obj)
	{
	}
	virtual void Copy(list<Muzafarov*>& l) {}

	void print()
	{
		cout << "M2" << endl;

		cout << "list: ";
		list<int*> ::iterator it;
		for (it = (*l).begin(); it != (*l).end(); it++)
			cout << **it << " ";

		cout << endl << "Str: ";
		for (int i = 0; i < 10; i++)
			cout << str[i];

		cout << endl << "f = " << *f << endl;
		cout << endl << "d = " << *d << endl;
	}
};

class DB
{
	list<Muzafarov*> l;
public:

	void Push_back(Muzafarov* obj)
	{
		l.push_back(obj);
	}

	void print()
	{
		cout << "---------------" << endl;
		list<Muzafarov*> ::iterator it;
		for (it = l.begin(); it != l.end(); it++)
			(*it)->print();
		cout << "---------------" << endl;
	}
	~DB()
	{
		for (list <Muzafarov*>::iterator it = l.begin(); it != l.end(); it++)
		{
			delete(*it);
			(*it) = 0;
		}
	}
	DB& operator=(const DB& obj)
	{

		if (this == &obj)
		{
			return *this;
		}

		for (list <Muzafarov*>::iterator it = l.begin(); it != l.end(); it++)
		{
			delete(*it);
		}
		l.clear();

		for (list <Muzafarov*>::const_iterator it = obj.l.begin(); it != obj.l.end(); it++)
		{
			(*it)->Copy(l);
		}

		return *this;
	}
	void Change()
	{
		for (list <Muzafarov*>::iterator it = l.begin(); it != l.end(); it++)
		{
			(*it)->Change();
		}
	}
};

int main()
{
	DB db1, db2;
	db1.Push_back(new Muzafarov_1);
	db1.Push_back(new Muzafarov_2);
	db1.Push_back(new Muzafarov_3);

	for (int i = 0; i < 2; i++) {
		db1.Push_back(new Muzafarov_1);
		db1.Push_back(new Muzafarov_2);
		db1.Push_back(new Muzafarov_3);
	}

	db1.Change();
	db2 = db1;

	db1.print();
	db2.print();
	return 0;
}