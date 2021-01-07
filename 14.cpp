/*
14. Check if the above inline add function takes more or less time than a non-inline version of add function.
*/

#include <bits/stdc++.h>

using namespace std;

// inline function
inline int add_inline(int a, int b, int c)
{
    return a + b + c;
}

// non-inline function
int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << "enter 3 numbers\n";
    int a, b, c;
    cin >> a >> b >> c;

    clock_t start, end;

    // time for inline function
    start = clock();
    int res = add_inline(a, b, c);
    end = clock();
    cout << "time for inline function: " << 1000 * double(end - start) / 1.0 * CLOCKS_PER_SEC << "\n";

    // time for non-inline function
    start = clock();
    res = add(a, b, c);
    end = clock();
    cout << "time for non-inline function: " << 1000 * double(end - start) / 1.0 * CLOCKS_PER_SEC << "\n";

    cout << "Inline function takes lesser time \n";
}
