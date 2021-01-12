/*
48. Vehicles may be either stopped of running in a lane. If two vehicles are running in opposite direction in a single
lane there is a chance of collision. Write a C++ program using exception handling to avoid collisions. You are
free to make necessary assumptions.
*/

/**
 * We assume each Car object has 2 data members - int lane (1 or 2) and int dir (up=1 and down=0).
 * if two cars c1 and c2 are on same lane and moving opposite to each other then collision will occur.
 * otherwise the cars can move safely without collision.
 */

#include <iostream>
using namespace std;

// Exception classes

class CollisionException
{
public:
    CollisionException() {}
};

class InvalidInputException
{
public:
    InvalidInputException() {}
};

class Car
{
    int lane, dir;

public:
    Car(int ll, int dd)
    {
        lane = ll;
        dir = dd;
    }
    void checkValidInput()
    {
        // lane = 1 or 2 and dir = 0 or 1
        if (lane < 1 || lane > 2 || dir < 0 || dir > 1)
            throw InvalidInputException();
        else
            cout << "Input validated !\n";
    }
    int checkSafeDriving(Car c)
    {
        int safe = 0;
        if (lane == c.lane)
        {
            // cars on same lane
            if (dir != c.dir) // opposite direction => collision chance
                throw CollisionException();
            else // same direction => no collision chance
                safe = 1;
        }
        else
            safe = 1; // different lanes
        return safe;
    }
};

int main()
{
    cout << "Lane is either 1 or 2.\nDriving direction: Up = 1 and Down = 0\n\n";

    int l, d;
    cout << "Enter lane and direction of Car 1\n";
    cin >> l >> d;
    Car c1(l, d);
    cout << "Enter lane and direction of Car 2\n";
    cin >> l >> d;
    Car c2(l, d);
    try
    {
        c1.checkValidInput();
        c2.checkValidInput();
        int isSafe = c1.checkSafeDriving(c2);
        if (isSafe == 1)
        {
            cout << "Cars are driving safely!\n";
        }
    }
    catch (InvalidInputException e)
    {
        cout << "Invalid input given for one or more cars\n";
    }
    catch (CollisionException e)
    {
        cout << "Cars are NOT safe, re-routing is necessary to avoid chances of collision!\n";
    }
}