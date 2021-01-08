/*
Write a template function max() that is capable of finding maximum of two things (that can be compared). Used
this function to find (i) maximum of two integers, (ii) maximum of two complex numbers (previous code may be
reused). Now write a specialized template function for strings (i.e. char *). Also find the maximum of two strings
using this template function.
*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }
    float magnitude()
    {
        return sqrt(real * real + imag * imag);
    }
    void disp()
    {
        cout << '(' << real << ',' << imag << ")\n";
    }
};

// template implementation

template <class T>
T maximum(T x, T y)
{
    return (x > y) ? x : y;
}

template <>
Complex maximum(Complex c1, Complex c2)
{
    return c1.magnitude() > c2.magnitude() ? c1 : c2;
}

template <>
string maximum(string s1, string s2)
{
    int mx = -1;
    for (int i = 0; i < min(s1.size(), s2.size()); i++)
    {
        if (s1[i] < s2[i])
        {
            mx = 1;
            break;
        }
        else if (s1[i] > s2[i])
        {
            mx = 0;
            break;
        }
    }
    if (mx == -1)
    {
        mx = (s1.size() < s2.size()) ? 1 : 0;
    }
    return (mx == 1) ? s2 : s1;
}

int main()
{
    cout << maximum(2, 5) << "\n";
    cout << maximum(4.6, 4.56) << "\n";
    cout << maximum('Z', 'z') << "\n";

    Complex c1(3, -4), c2(5, -2);
    Complex cmax = maximum(c1, c2);
    cmax.disp();

    string s1 = "elephant", s2 = "aabcd";
    cout << maximum(s1, s2) << "\n";
}