/* Write a function that takes an integer and returns the factorial of that number. Declare function parameter as
const. Call the function with some argument from main function, store the result and print it. */

#include <iostream>
using namespace std;

int fact(const int num);

int main()
{
    int x = fact(5);
    cout << "Factorial of 5 is " << x;
}

int fact(const int num)
{
    if (num == 1 || num == 0)
        return 1;
    return num * fact(num - 1);
}