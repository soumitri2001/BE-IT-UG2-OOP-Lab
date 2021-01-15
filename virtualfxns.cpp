#include <iostream>
using namespace std;

class Base
{
public:
    void show()
    {
        cout << "base class fxn show()\n";
    }
    virtual void print()
    {
        cout << "base class print() fxn \n";
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "derived class fxn show()\n";
    }
    void print()
    {
        cout << "derived class print() fxn \n";
    }
};

int main()
{
    Base *baseptr;
    Derived derivedobj;

    baseptr = &derivedobj;

    baseptr->print(); // derived class print() called
    baseptr->show();  // base class show() called
}