/**
 * Write a simple class that represents a class of geometrical points each of which has three coordinates. The class
* should have appropriate constructor(s). Also add a m:!ember function distance() that calculates Euclidian
* distance between two points. Now create two points, find the distance between them and print it.
 */

#include <iostream>
#include <math.h>
using namespace std;

class Point3D
{
private:
    double x;
    double y;
    double z;

public:
    Point3D();
    Point3D(double x, double y, double z);
    static double distance(Point3D, Point3D);
};

Point3D::Point3D()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point3D::distance(Point3D p1, Point3D p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main()
{
    Point3D p1(3, 4, 5);
    Point3D p2(7, 3, 10);

    cout << "distance = " << Point3D::distance(p1, p2) << "\n";
}
