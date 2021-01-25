/* Now write another function swap() that takes two strings (character array) and interchanges them without
reference parameters. Test this function using some arguments. Rewrite the function using reference parameters.
Again test this function with some arguments */

#include <iostream>
using namespace std;

void swap(string(&x), string(&y))
{
    string temp = x;
    x = y;
    y = temp;
}

int main()
{
    string a = "Soumitri";
    string b = "Chattopadhyay";
    cout << "value of a is " << a << " and  b is " << b << endl;
    swap(a, b);
    cout << "After swap, with reference ";
    cout << "value of a is " << a << " and b is " << b << endl;
    return 0;
}
