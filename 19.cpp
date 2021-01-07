/**
 * 19.Write a class for the geometrical shape rectangle. Write suitable constructors and member functions. Add a
 * member function area() that calculates the area of a rectangle. Create 4 rectangles and print their respective area. 
*/

#include <iostream>
#include <math.h>

using namespace std;

class Rectangle
{
private:
    double length;
    double breadth;

public:
    Rectangle(double length, double breadth);
    double area();
    double perimeter();
    void printArea();
};

Rectangle::Rectangle(double length, double breadth)
{
    this->length = length;
    this->breadth = breadth;
}

double Rectangle::area()
{
    return (this->length) * (this->breadth);
}

double Rectangle::perimeter()
{
    return 2 * (this->length + this->breadth);
}

void Rectangle::printArea()
{
    cout << "area is = " << this->area() << "\n";
}

int main()
{
    Rectangle r1(2, 5);
    Rectangle r2(4, 7);
    Rectangle r3(1.7, 6.5);
    Rectangle r4(15, 15);

    r1.printArea();
    r2.printArea();
    r3.printArea();
    r4.printArea();
}