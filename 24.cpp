// 24. Write some programs to understand the notion of constant member functions, mutable data members etc.

#include <iostream>
using namespace std;

class Point
{
    int x, y;
    mutable int z;

public:
    Point()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    void setX(int xx)
    {
        x = xx;
    }
    void setY(int yy)
    {
        y = yy;
    }
    void setZ(int zz) const
    {
        /* although this is const function,
         still it can change value of z
        as z has been declared as mutable */
        z = zz;
    }
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
    int getZ() const
    {
        return z;
    }
};

int main()
{
    Point p;
    p.setX(2);
    p.setY(5);
    p.setZ(-3);

    cout << p.getX() << "," << p.getY() << "," << p.getZ() << "\n";

    p.setZ(6);
    cout << p.getX() << "," << p.getY() << "," << p.getZ() << "\n";
}