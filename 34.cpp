/*
34. Design and implement class(es) to support the following main program.
int main() {
IntArray i(10);
for(int k = 0; k < 10; k++)
i[k] = k;
cout << i;
return 0;
}
*/

#include <iostream>
using namespace std;

class IntArray
{
    int *arr;
    int size;

public:
    IntArray(int sz = 1)
    {
        size = sz;
        arr = (int *)malloc(sizeof(int) * size);
    }
    int &operator[](const int idx)
    {
        return arr[idx];
    }
    friend ostream &operator<<(ostream &os, const IntArray &ia)
    {
        for (int i = 0; i < ia.size; i++)
        {
            cout << ia.arr[i] << " ";
        }
        cout << "\n";
        return os;
    }
};

int main()
{
    IntArray i(10);
    for (int k = 0; k < 10; k++)
        i[k] = k;
    cout << i;
    return 0;
}