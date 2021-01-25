/* Write a function swap() that takes two integer arguments and interchanges the values of those arguments using
reference. Now in the main function, instantiate two integer variables with some values. Print their values. Call
the swap function with these variables. Finally print the values of those variables. Check the result.
 */

#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 5, b = 0;
    cout << "value of a is " << a << " b is " << b << endl;
    swap(a, b);
    cout << "After swap, ";
    cout << "value of a is " << a << " b is " << b << endl;
}
