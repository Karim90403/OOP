#include<iostream>
#include<fstream>
#include<string>
#include<vector> 
#include<set>  
#include<map>  
#include<algorithm>
#include<cmath>
#include"tchar.h"

const double PI = 3.141592653589793;

using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
    Shape() {}
    virtual double perimeter()
    {
        return 0;
    }
};

class Circle : public Shape
{
public:
    double radius;
    Circle(double r) : Shape()
    {
        radius = r;
    }
    double perimeter()
    {
        return 2 * PI * radius;
    }
};

class Square : public Shape
{
public:
    double side;
    Square(double s) : Shape()
    {
        side = s;
    }
    double perimeter()
    {
        return 4 * side;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    vector <Shape*> v;

    cout << "Circle perimeters" << endl;
    for (int i = 0; i < 3; i++)
    {
        v.push_back(new Circle(i + 1));
        cout << v[i]->perimeter() << endl;
    }

    cout << "Squre perimeters" << endl;
    for (int i = 3; i < 6; i++)
    {
        v.push_back(new Square(i));
        cout << v[i]->perimeter() << endl;
    }

    for (int i = 0; i < 6; i++)
    {
        delete v[i];
    }
    return 0;
}