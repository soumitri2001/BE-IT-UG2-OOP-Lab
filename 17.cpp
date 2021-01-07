/*
17. Consider function add() in 3. Specify the default values for second and third parameters to 0 (zero). Now call this
function with three, two and one arguments and see the result.
*/

#include <iostream>

using namespace std;

int add(int a, int b = 0, int c = 0)
{
    return a + b + c;
}

int main()
{
    cout << add(10, 20, 40) << "\n";
    cout << add(10, 20) << "\n";
    cout << add(10) << "\n";
}