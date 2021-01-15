#include <iostream>
using namespace std;

class Shape // abstract class
{
public:
    virtual void getArea() = 0; // pure virtual fxn
};

class Circle : public Shape
{
public:
    void getArea()
    {
        cout << "enter radius\n";
        int r;
        cin >> r;
        cout << "area = " << 3.14 * r * r << "\n";
    }
};

int main()
{
    Circle c1;
    c1.getArea();
}