/*
16.Write two overloaded functions print() such that one prints the elements of a vector and the other prints elements
of a matrix. Note that a vector and a matrix may be represented as a one-dimensional array and a
two-dimensional array respectively
*/

#include <iostream>

using namespace std;

void print(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void print(int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    print(arr, len);

    int m = 4, n = 3, k = 1;
    int **mat;
    mat = new int *[m];
    for (int i = 0; i < m; i++)
    {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = k++;
        }
    }
    print(m, n, mat);
}