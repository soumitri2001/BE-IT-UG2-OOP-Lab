/*
13. Write an inline function add() that takes three integer arguments and returns the sum of these arguments
*/

#include <iostream>

using namespace std;

inline int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << "enter 3 numbers\n";
    int a, b, c;
    cin >> a >> b >> c;
    cout << add(a, b, c) << "\n";
}