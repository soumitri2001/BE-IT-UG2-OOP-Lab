/*
Write a class IntArray for one dimensional integer array. Implement the necessary constructor, copy constructor,
and destructor (if necessary) in this class. Implement other member functions to perform operations, such adding
two arrays, reversing an array, sorting an array etc. Create an IntArray object having elements 1, 2 and 3 in it.
Print its elements. Now, create another IntArray object which is an exact copy of the previous object. Print its
elements. Now, reverse the elements of the last object. Finally print elements of both the objects.
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 10

class IntArray
{
private:
    int arr[MAX_SIZE];
    int size;

public:
    IntArray(int arr[], int size);
    IntArray(const IntArray &ia); // copy constructor
    IntArray add(IntArray);
    void reverse();
    void display();
};

IntArray::IntArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = arr[i];
    }
    this->size = size;
}

IntArray::IntArray(const IntArray &ia)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = ia.arr[i];
    }
    size = ia.size;
}

IntArray IntArray::add(IntArray ia)
{
    int temp[size] = {0};
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i] + ia.arr[i];
    }
    IntArray res = IntArray(temp, size);
    return res;
}

void IntArray::reverse()
{
    int l = 0, u = size - 1;
    while (l < u)
    {
        int temp = arr[l];
        arr[l] = arr[u];
        arr[u] = temp;
        l++;
        u--;
    }
}

void IntArray::display()
{
    cout << "displaying IntArray:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};

    IntArray ia = IntArray(a, 3);
    IntArray ib = IntArray(b, 3);

    IntArray ic = ia.add(ib);
    ic.display();

    IntArray icopy = IntArray(ib);
    icopy.display();

    icopy.reverse();

    icopy.display();
}
