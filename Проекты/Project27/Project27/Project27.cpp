#include <iostream>
#include <vector>
#include <string>
using namespace std;

class House {
public:
    string* type;
    House() {}
    virtual ~House()
    {
        delete type;
    }
    House(const House& asd) {
        type = new string(*asd.type);
    }
    virtual House* copy()
    {
        return new House(*this);
    }

};

class Wooden : public House {
public:
    Wooden()
    {

        type = new string("Wooden");
    }
    virtual Wooden* copy()
    {
        return new Wooden(*this);
    }
};

class Brick : public House {
public:
    int b;
    Brick()
    {
        type = new string("Brick");
    }
    virtual Brick* copy()
    {
        return new Brick(*this);

    }
};

int main()
{
    vector<House*> data1;

    data1.push_back(new Brick);
    data1.push_back(new Wooden);
    data1.push_back(new Wooden);
    data1.push_back(new Brick);
    data1.push_back(new Brick);

    vector<House*> data2;

    for (vector <House*>::iterator it = data1.begin(); it != data1.end(); ++it) {
        House* new_obj = (*it)->copy();
        data2.insert(data2.end(), new_obj);
    }

    for (int i = 0; i < 5; i++)
    {
        delete data1[i];
    }

    for (int i = 0; i < 5; i++)
    {
        delete data2[i];
    }

    return 0;
}