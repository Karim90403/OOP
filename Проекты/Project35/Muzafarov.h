#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cwchar>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt>
#include <random>
#include <ctime>

using namespace std;

class Muzafarov
{
public:
	
	vector<wstring> m_txt;
	Muzafarov() {}
	virtual void push(vector<wstring>& v, int start, int end);
	virtual Muzafarov* copy();
	virtual ~Muzafarov() {}
	virtual void print();
	virtual string checkClass();
};

