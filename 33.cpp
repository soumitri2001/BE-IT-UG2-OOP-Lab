/*
35. Write extra functions/operators required in the INT class to make main program work. Provide suitable
implementation for the added functions/operators.
*/

#include <iostream>
using namespace std;

class INT
{
    int i;

public:
    INT(int a) : i(a) {}
    ~INT() {}
    INT operator++()
    {
        INT temp(0);
        temp.i = ++i;
        return temp;
    }
    INT operator++(int d)
    {
        INT temp(0);
        temp.i = i++;
        return temp;
    }
    operator int()
    {
        return i;
    }
};
int main()
{
    int x = 3;
    INT y = x;
    y++ = ++y;
    x = y;
    return 0;
}