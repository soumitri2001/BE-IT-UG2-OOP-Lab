// 10. Check if a swap function using reference takes more or less time than one using non-reference.

#include <iostream>
#include <time.h>
using namespace std;

void swapRef(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapPointer(int *a, int *b)
{
    int temp = *a;
    *a = (*b);
    *b = temp;
}

int main()
{
    cout.precision(100);

    int a = 10, b = 5;
    clock_t startRef = clock();
    swapRef(a, b);
    clock_t endRef = clock();

    clock_t startPointer = clock();
    swapPointer(&a, &b);
    clock_t endPointer = clock();

    double refTime = ((double)(endRef - startRef)) / CLOCKS_PER_SEC;
    double pointerTime = ((double)(endPointer - startPointer)) / CLOCKS_PER_SEC;

    printf("Swap by reference took %lf secs\n", refTime);
    printf("Swap by pointer took %lf secs\n", pointerTime);
    if (refTime > pointerTime)
    {
        printf("Swap by pointer was faster by %lf secs\n",
               refTime - pointerTime);
    }
    else if (pointerTime > refTime)
    {
        printf("Swap by pointer was faster by %lf secs\n",
               pointerTime - refTime);
    }
    else
    {
        cout << "perhaps the time taken by either process was too trivial to be measured very precisely !" << endl;
    }
}
