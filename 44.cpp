#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
public:
    Shape() {}
    virtual float getArea() = 0;
    virtual float getVolume() = 0;
    virtual string getShape() = 0;
};

class TwoDShape : public Shape
{
public:
    virtual float getArea() = 0;
    virtual string getShape() = 0;
};

class ThreeDShape : public Shape
{
public:
    virtual float getArea() = 0;
    virtual float getVolume() = 0;
    virtual string getShape() = 0;
};

class Circle : public TwoDShape
{
    float radius;

public:
    Circle(float rad)
    {
        radius = rad;
    }
    string getShape() { return "circle"; }
    float getArea()
    {
        return 3.14 * radius * radius;
    }
    float getVolume() { return 0; }
};

class Ellipse : public TwoDShape
{
    float major_axis, minor_axis;

public:
    Ellipse(float maj, float min)
    {
        major_axis = maj;
        minor_axis = min;
    }
    string getShape() { return "ellipse"; }
    float getArea()
    {
        return 3.14 * major_axis * minor_axis / 4;
    }
    float getVolume() { return 0; }
};

class Triangle : public TwoDShape
{
    float s1, s2, s3;

public:
    Triangle(float a, float b, float c)
    {
        s1 = a;
        s2 = b;
        s3 = c;
    }
    string getShape() { return "triangle"; }
    float getArea()
    {
        float sp = (s1 + s2 + s3) / 2;
        return sqrt(sp * (sp - s1) * (sp - s2) * (sp - s3));
    }
    float getVolume() { return 0; }
};

class Sphere : public ThreeDShape
{
    float radius;

public:
    Sphere(float rad)
    {
        radius = rad;
    }
    string getShape() { return "sphere"; }
    float getArea()
    {
        return 4 * 3.14 * radius * radius;
    }
    float getVolume()
    {
        return 4 * 3.14 * radius * radius * radius / 3;
    }
};

class Cube : public ThreeDShape
{
    float side;

public:
    Cube(float s)
    {
        side = s;
    }
    string getShape() { return "cube"; }
    float getArea()
    {
        return 6 * side * side;
    }
    float getVolume()
    {
        return side * side * side;
    }
};

int main()
{

    Circle c = Circle(5);
    Ellipse e = Ellipse(2, 3);
    Triangle t = Triangle(3, 4, 5);
    Sphere s = Sphere(4);
    Cube cu = Cube(6);

    Shape *S[5];
    S[0] = &c;
    S[1] = &e;
    S[2] = &t;
    S[3] = &s;
    S[4] = &cu;

    for (int i = 0; i < 5; i++)
    {
        cout << "SHAPE " << i + 1 << "\n";
        cout << "shape: " << S[i]->getShape() << "\n";
        cout << "area: " << S[i]->getArea() << "\n";
        cout << "volume: " << S[i]->getVolume() << "\n";
        cout << "\n";
    }
}