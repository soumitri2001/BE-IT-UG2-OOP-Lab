/*
Two integers are taken from keyboard. Then perform division operation. Write a try block to throw an exception
when division by zero occurs and appropriate catch block to handle the exception thrown.
*/

#include <iostream>
using namespace std;

class DivisionByZeroException
{
public:
    DivisionByZeroException() {}
};

int main()
{
    float x, y, res;
    while (true) // infinite loop that keeps taking x and y as input till exception occurs
    {
        cout << "enter x and y to get x/y \n";
        cin >> x >> y;
        try
        {
            if (y == 0)
                throw DivisionByZeroException();
            else
            {
                res = x / y;
                cout << "Quotient=" << res << "\n";
            }
        }
        catch (DivisionByZeroException e)
        {
            cout << "cannot divide by zero \nException thrown...terminating program\n";
            break;
        }
    }
}
