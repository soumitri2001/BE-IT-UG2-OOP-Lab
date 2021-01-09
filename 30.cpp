/*
Write a class Point which stores coordinates in (x, y) form. Define necessary constructor, destructor and other
reader/writer functions. Now overload '-' operator to calculate the distance between two points.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Point
{
  float x, y;

public:
  Point()
  {
    x = 0;
    y = 0;
  }
  Point(float xx, float yy)
  {
    x = xx;
    y = yy;
  }
  float operator-(Point);
  void disp();
};

float Point::operator-(Point p)
{
  return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

void Point::disp()
{
  cout << x << "," << y << "\n";
}

int main()
{
  Point p1(2, 5), p2(5, -4);
  float dist = p1 - p2;
  cout << "p1 = ";
  p1.disp();
  cout << "p2 = ";
  p2.disp();
  cout << "Distance between p1 and p2 = " << dist << "\n";
}