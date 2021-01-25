/* Create a factorial table using cout as follows:
1! = 1
2! = 2
3! = 6
…
6! = 720 */

#include <iostream>
using namespace std;

int main()
{
    int i = 1, fact = 1;
    while (i <= 6)
    {
        cout << i << "! = " << fact << "\n";
        i++;
        fact *= i;
    }
}