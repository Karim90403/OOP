#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <cmath>
#include <windows.h> 

using namespace std;

class Koordinates
{
public:
	int x, y;
	Koordinates();
	Koordinates(int x1, int y1);
	~Koordinates();
};

