#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cwchar>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include <codecvt>

using namespace std;

class Word
{
public:
	vector<wstring> v;
	Word() {}
	virtual void push(wstring word);
	virtual ~Word() {}
};