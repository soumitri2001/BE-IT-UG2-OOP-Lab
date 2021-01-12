/*
Implement a class “ Quadratic ” that represents second-degree polynomial i.e. polynomial of type ax 2 +bx+c. The
class will require three data members corresponding to a, b and c. Implement the following:
a) A constructor (including a default constructor which create a null polynomial)
b) Overload the addition operator to add two polynomials of degree 2.
c) Overload << and >> operators to print and read polynomials.
d) A function to compute the value of polynomial for a given x.
e) A function to compute roots of the equation ax^2 +bx+c=0. Remember, root may be a complex number.
You may implement “ Complex ” class to represent root of the quadratic equation.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
    float real, img;

public:
    Complex(float r = 0.0, float i = 0.0)
    {
        real = r;
        img = i;
    }
    void disp()
    {
        cout << "(" << real << "," << img << "i)\n";
    }
};

class Tuple
{
    // data structure to hold two complex numbers
    Complex first, second;

public:
    Tuple(Complex ff, Complex ss)
    {
        first = ff;
        second = ss;
    }
    Complex getFirst()
    {
        return first;
    }
    Complex getSecond()
    {
        return second;
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
    friend istream &operator>>(istream &is, Quadratic &q)
    {
        cout << "enter a,b,c\n";
        is >> q.a >> q.b >> q.c;
        return is;
    }
    friend ostream &operator<<(ostream &os, Quadratic &q)
    {
        cout << "Quadratic coefficients:";
        os << "[" << q.a << "," << q.b << "," << q.c << "]\n";
        return os;
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
    Tuple computeRoots()
    {
        if (a == 0)
        {
            if (b == 0)
            {
                if (c == 0)
                    cout << "All complex numbers\n";
                else
                    cout << "no solution\n";
                Tuple root(Complex(0, 0), Complex(0, 0));
                return root;
            }
            float x = -c / b;
            Tuple root(Complex(x, 0), Complex(x, 0));
            return root;
        }
        float D = b * b - 4 * a * c;
        if (D < 0)
        {
            // complex roots
            float r = -b / (2 * a), i = sqrt(abs(D)) / (2 * a);
            Tuple root(Complex(r, i), Complex(r, -i));
            return root;
        }
        else
        {
            // real roots => imag = 0
            float x1 = (-b + sqrt(D)) / (2 * a);
            float x2 = (-b - sqrt(D)) / (2 * a);
            Tuple root(Complex(x1, 0), Complex(x2, 0));
            return root;
        }
    }
};

int main()
{
    Quadratic q1;
    cout << "Quadratic q1\n";
    cin >> q1;
    cout << "solving q1=0:\n";
    Tuple root = q1.computeRoots();
    cout << "x1=";
    root.getFirst().disp();
    cout << "x2=", root.getSecond().disp();

    cout << "\n\n";

    Quadratic q2;
    cout << "Quadratic q2\n";
    cin >> q2;
    cout << "solving q2=0:\n";
    root = q2.computeRoots();
    cout << "x1=";
    root.getFirst().disp();
    cout << "x2=", root.getSecond().disp();

    cout << "\n\n";

    Quadratic q3 = q1 + q2;
    cout << "After adding q1 and q2, coefficients = " << q3;
    cout << "solving q3=0:\n";
    root = q3.computeRoots();
    cout << "x1=";
    root.getFirst().disp();
    cout << "x2=", root.getSecond().disp();
}