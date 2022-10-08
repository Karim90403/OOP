#include<iostream>
#include"tchar.h"

using namespace std;

class Welcome
{
private:
	char* m_data;
public:
	Welcome()
	{
		m_data = new char[14];
		const char* init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
		cout << m_data;
	}
	~Welcome()
	{
		delete[] m_data;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	Welcome();

	return 0;
}