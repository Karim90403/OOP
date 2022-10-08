#include<iostream>
#include<fstream>
#include<string>
#include<vector> 
#include<set>  
#include<map>  
#include<algorithm>
#include<cmath>
#include"tchar.h"

using namespace std;


class Base
{
	int* i;
	double d;
public:
	Base() : i(new int), d(22.33)
	{
		*i = 0;
	}
	virtual ~Base()
	{
		delete i;
		i = 0;
	}

	int get() { return *i; }
	double  get()const { return d; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Base b;
	const Base bc;
	cout << b.get() << endl;
	cout << bc.get() << endl;

	return 0;
}
