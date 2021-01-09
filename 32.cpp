/*
Implement a class “ Quadratic ” that represents second-degree polynomial i.e. polynomial of type ax 2 +bx+c. The
class will require three data members corresponding to a, b and c. Implement the following:
a) A constructor (including a default constructor which create a null polynomial)
b) Overload the addition operator to add two polynomials of degree 2.
c) Overload << and >> operators to print and read polynomials.
d) A function to compute the value of polynomial for a given x.
e) A function to compute roots of the equation ax 2 +bx+c=0. Remember, root may be a complex number.
You may implement “ Complex ” class to represent root of the quadratic equation.
*/

// TODO: parts c,e

#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
    float real, img;

public:
    Complex(int r)
    {
        real = r;
        img = 0;
    }
    Complex(float r, float i)
    {
        real = r;
        img = i;
    }
    void disp()
    {
        cout << real << "," << img << "\n";
    }
};

class Quadratic
{
    float a, b, c;

public:
    Quadratic()
    {
        a = b = c = 0;
    }
    Quadratic(float aa, float bb, float cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
    float computePolynomial(float x)
    {
        return a * pow(x, 2) + b * x + c;
    }
    Quadratic operator+(Quadratic q)
    {
        Quadratic temp;
        temp.a = a + q.a;
        temp.b = b + q.b;
        temp.c = c + q.c;
        return temp;
    }
};