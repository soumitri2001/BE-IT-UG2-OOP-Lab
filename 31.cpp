// Design a class Complex that includes all the necessary functions and operators like =, +, -, *, /.

#include <iostream>
using namespace std;

class Complex
{
    float real, img;

public:
    Complex()
    {
        real = img = 0;
    }
    Complex(float r, float i)
    {
        real = r;
        img = i;
    }
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.img = img - c.img;
        return temp;
    }
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = real * c.real - img * c.img;
        temp.img = real * c.img + img * c.real;
        return temp;
    }
    Complex operator/(Complex c)
    {
        Complex temp;
        temp.real = real * c.real - img * c.img;
        temp.real /= (c.real * c.real + c.img * c.img);
        temp.img = real * c.img + img * c.real;
        temp.img /= (c.real * c.real + c.img * c.img);
        return temp;
    }
    void disp()
    {
        cout << real << "," << img << "\n";
    }
};

int main()
{
    Complex c1(2, 5), c2(-5, 3), c3;
    c3 = c1 + c2;
    c3.disp();
    c3 = c1 - c2;
    c3.disp();
    c3 = c1 * c2;
    c3.disp();
    c3 = c1 / c2;
    c3.disp();
}