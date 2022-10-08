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

template < class T>

class  Base
{
public:
	Base(T  a)
	{
		p = a;
	}
	void print()
	{
		cout << p << endl;
	}

private:
	T  p;
};

int _tmain(int argc, _TCHAR* argv[])
{
	// Base b // Ошибка:нужно указать тип шаблона
	Base <int> bi(22);  // ok
	Base <double> bd(22.84);  // ok     
	Base <string> bs("test");  // ok   
	bi.print();
	bd.print();
	bs.print();
	return 0;
}