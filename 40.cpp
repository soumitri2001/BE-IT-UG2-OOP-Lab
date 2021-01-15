#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "classA\n";
    }
};

class B
{
public:
    B()
    {
        cout << "classB\n";
    }
};

class C
{
public:
    C()
    {
        cout << "classC\n";
    }
};

class D : public A, public B
{
public:
    D()
    {
        cout << "classD\n";
    }
};

class E : public B, public C
{
public:
    E()
    {
        cout << "classE\n";
    }
};

class F : public D, public E
{
public:
    F()
    {
        cout << "classF\n";
    }
};

int main()
{
    D d;
    cout << "\n";
    E e;
    cout << "\n";
    F f;
    cout << "\n";
}