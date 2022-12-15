#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <cmath>

using namespace std;

class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual void print();
};


