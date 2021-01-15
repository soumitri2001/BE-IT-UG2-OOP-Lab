/*
Write class definitions for the following class hierarchy
Circle--------->Shape2D<------------Rectangle
The Shape2D class represents two dimensional shapes that should have pure virtual functions area(), perimeter()
etc. Implement these functions in Circle and Rectangle. Also write proper constructor(s) and other functions you
think appropriate in the Circle and Rectangle class. Now create an array of 5 Shape2D pointers. Create 3 Circle
and 2 Rectangles objects and place their addresses in that array. Use a loop to print area and perimeter of all
shapes on this array.
*/

#include <iostream>
using namespace std;

class Shape2D
{
protected:
    float height, width;

public:
    Shape2D(float h = 0, float w = 0)
    {
        height = h;
        width = w;
    }
    virtual float area()
    {
        return height * width;
    }
    virtual float perimeter()
    {
        return 2 * (height + width);
    }
};

class Circle : public Shape2D
{
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
    float perimeter()
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape2D
{
public:
    Rectangle(int h, int w)
    {
        height = h;
        width = w;
    }
};

int main()
{

    Circle c1(1), c2(4.5), c3(5);
    Rectangle r1(4, 3), r2(5, 5);

    Shape2D *S[5];

    S[0] = &c1;
    S[1] = &c2;
    S[2] = &c3;

    S[3] = &r1;
    S[4] = &r2;

    for (int i = 0; i < 5; i++)
    {
        cout << "For Shape: " << i + 1 << "\n";
        cout << "Area: " << S[i]->area() << "\n";
        cout << "Perimeter: " << S[i]->perimeter() << "\n";
        cout << "\n\n";
    }
}