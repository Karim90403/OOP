#include<iostream>
#include<vector>
#include"tchar.h"

using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Construct Base" << endl;
	}
	virtual ~Base()
	{
		cout << "Destruct Base" << endl;
	}
};

class Child :public Base {
public:
	Child()
	{
		cout << "Construct Child" << endl;
	}
	~Child()
	{
		cout << "Destruct Child" << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector <Base*>v(2);
	v[0] = new Base();
	v[1] = new  Child();

	for (int i = 0; i < v.size(); i++)
	{
		delete v[i]; v[i] = 0;
	}
	return 0;
}
