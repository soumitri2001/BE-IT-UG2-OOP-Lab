#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        cout << "Inside Base1 class\n";
    }
};

class Base2
{
public:
    Base2()
    {
        cout << "Inside Base2 class\n";
    }
};

class Derived : public Base1, public Base2
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
