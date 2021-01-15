#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Inside Base class\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Inside Derived class\n";
    }
};

int main()
{
    Derived obj;
}
