/*
Write the definition for a class called Complex that has private floating point data members for storing real and
imaginary parts. The class has the following public member functions:
setReal() and setImg() to set the real and imaginary part respectively.
getReal() and getImg() to get the real and imaginary part respectively.
disp() to display complex number object
sum() to sum two complex numbers & return a complex number
Write main function to create three complex number objects. Set the value in two objects and call sum() to
calculate sum and assign it in third object. Display all complex numbers.
*/

#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
    float real, imag;

public:
    void setReal(float r);
    void setImag(float i);
    double getReal();
    double getImag();
    Complex sum(Complex);
    void disp();
};

void Complex::setReal(float r)
{
    this->real = r;
}
void Complex::setImag(float i)
{
    this->imag = i;
}
double Complex::getReal()
{
    return this->real;
}
double Complex::getImag()
{
    return this->imag;
}

Complex Complex::sum(Complex c)
{
    Complex temp;

    temp.real = this->real + c.real;
    temp.imag = this->imag + c.imag;

    return temp;
}

void Complex::disp()
{
    cout << '(' << this->real << "," << this->imag << ")\n";
}

int main()
{
    Complex c1, c2;

    c1.setReal(3);
    c1.setImag(-4);

    c1.disp();

    c2.setReal(-7);
    c2.setImag(24);

    c2.disp();

    Complex c3 = c1.sum(c2);
    cout << "sum is: ";
    c3.disp();
}