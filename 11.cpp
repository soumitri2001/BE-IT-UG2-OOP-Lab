// Write a function that takes an integer and returns the factorial of that number. Declare function parameter as read
// only reference.Call the function with some argument from main function, store the result and print it.

#include <iostream>
using namespace std;

int fact(const int &n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    cout << "Enter a number \n";
    int n;
    cin >> n;
    int ans = fact(n);
    cout << "Factorial of " << n << " is " << ans;
}
