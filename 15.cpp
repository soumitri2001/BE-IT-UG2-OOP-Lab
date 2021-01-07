/*
15. Consider the following two scenarios:
a) We want to find out the maximum between three integers.
b) We also want to find out the maximum element of an array of integers.
Write two overloaded functions for these two scenarios
*/

#include <iostream>

using namespace std;

int max(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int max(int a[], int len)
{
    int mx = a[0];
    for (int i = 1; i < len; i++)
    {
        if (a[i] > mx)
            mx = a[i];
    }
    return mx;
}

int main()
{
    int arr[] = {45, 21, -4, 5, 13, 54};
    int len = sizeof(arr) / sizeof(arr[0]);
    int a = 23, b = 56, c = 12;
    cout << max(a, b, c) << "\n";
    cout << max(arr, len) << "\n";
}