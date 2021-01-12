/*
37. Design and implement class(es) to support the following code segment.
Index in(4), out(10);
int x = in;
int y = in + out;
in = 2;
Integer i;
i = in;
*/

#include <iostream>
using namespace std;

class Index
{
    int data;

public:
    Index(int dd = 0)
    {
        data = dd;
    }
    Index(const Index &in)
    {
        data = in.data;
    }
    int getIndex()
    {
        return data;
    }
    Index operator+(const Index in)
    {
        Index temp;
        temp.data = data + in.data;
        return temp;
    }
    operator int()
    {
        return data;
    }
};

class Integer
{
    int data;

public:
    Integer() {}
    Integer(Index in)
    {
        data = in.getIndex();
    }
};

int main()
{
    Index in(4), out(10);
    int x = in;
    int y = in + out;
    in = 2;
    Integer i;
    i = in;
}