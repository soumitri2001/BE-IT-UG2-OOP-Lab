#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
protected:
    int height, width;

public:
    Shape(int h = 1, int w = 1)
    {
        height = h;
        width = w;
    }
    int getArea()
    {
        return height * width;
    }
};

class Rectangle : public Shape
{
    float diag;

public:
    Rectangle(int h, int w)
    {
        height = h;
        width = w;
        diag = sqrt(pow(height, 2) + pow(width, 2));
    }
    float getArea()
    {
        return sqrt(pow(diag, 2) - pow(height, 2)) * height;
    }
};

int main()
{
    Rectangle rect(2, 3);
    cout << "area = " << rect.getArea() << "\n";
}