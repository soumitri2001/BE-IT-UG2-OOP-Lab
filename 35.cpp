/*
35. You are given a main program:
int main() {
Integer a = 4, b = a, c;
c = a+b++;
int i = a;
cout << a << b << c;
return 0;
}
Design and implement class(es) to support the main program.
*/

#include <iostream>
using namespace std;

class Integer
{
    int data;

public:
    Integer(int d = 0)
    {
        data = d;
    }
    Integer(const Integer &i)
    {
        data = i.data;
    }
    Integer operator+(const Integer i)
    {
        Integer temp;
        temp.data = data + i.data;
        return temp;
    }
    Integer operator++(int d)
    {
        Integer temp;
        temp.data = data++;
        return temp;
    }
    operator int()
    {
        return data;
    }
    friend ostream &operator<<(ostream &os, const Integer &i)
    {
        cout << i.data << " ";
        return os;
    }
};

int main()
{
    Integer a = 4, b = a, c;
    c = a + b++;
    int i = a;
    cout << a << b << c;
    return 0;
}