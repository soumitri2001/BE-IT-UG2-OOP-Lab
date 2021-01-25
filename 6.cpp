/* Write a program that defines a constant PI and takes radius of a circle from keyboard and prints area of that
circle. */

#include <iostream>
using namespace std;

const float PI = 3.14;

int main()
{
    cout << "Enter radius\n";
    int radius;
    cin >> radius;
    cout << "The area of circle is " << PI * radius * radius << "\n";
}