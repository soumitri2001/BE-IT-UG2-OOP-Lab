// Write a program to print 1 to 10 using a for loop. Declare the loop variable inside the for loop. Check the scope
// of this variable

#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << endl;
    }
    // scope is only defined within for loop
}