// 45. Write a program to illustrate the role of virtual destructor.

#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base class constructor invoked\n";
    }
    virtual ~Base()
    {
        cout << "Base class destructor invoked\n";
    }
    virtual void func()
    {
        cout << "Base class func() invoked\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived class constructor invoked\n";
    }
    ~Derived()
    {
        cout << "Derived class destructor invoked\n";
    }
    void func()
    {
        cout << "Derived class func() invoked\n";
    }
};

int main()
{

    Base *b1 = new Base();
    cout << "\n";

    Base *b2 = new Derived();
    cout << "\n";

    b1->func();
    b2->func();
    cout << "\n";

    delete b1; // Base class destructor invoked, as expected
    cout << "\n";

    delete b2;
    // here first the Derived class destructor is invoked and then the Base class destructor as Base has a virtual destructor
    // if Base class did not have a virtual destructor then only the Base class destructor would have been invoked which
    // would have caused memory leak.
}