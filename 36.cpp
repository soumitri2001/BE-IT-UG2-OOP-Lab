/*
Design and implement class(es) to support the following code segment.
Table t(4, 5), t1(4, 5);
cin >> t;
t[0][0] = 5;
int x = t[2][3];
t1 = t;
cout << t << “\n” << t1;
*/

#include <iostream>
using namespace std;

class Array
{
public:
    int *arr;
    int length;
    Array(int k = 0)
    {
        arr = (int *)malloc(sizeof(int) * k);
        length = k;
        for (int i = 0; i < length; i++)
            arr[i] = 0;
    }
    int &operator[](int k)
    {
        return arr[k];
    }
    void show()
    {
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

class Table
{
    Array *tab;
    int row, col;

public:
    Table(int k = 0, int l = 0)
    {
        row = k;
        col = l;
        tab = (Array *)malloc(sizeof(Array) * k);
        for (int i = 0; i < k; i++)
            tab[i] = Array(l);
    }
    Array &operator[](int k)
    {
        return tab[k];
    }
    void show()
    {
        for (int i = 0; i < row; i++)
            tab[i].show();
    }
    friend istream &operator>>(istream &is, Table tab)
    {
        for (int i = 0; i < tab.row; i++)
        {
            for (int j = 0; j < tab.col; j++)
            {
                cin >> tab[i][j];
            }
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, Table tab)
    {
        for (int i = 0; i < tab.row; i++)
        {
            for (int j = 0; j < tab.col; j++)
            {
                cout << tab[i][j] << " ";
            }
            cout << "\n";
        }
        return os;
    }
};
int main()
{
    Table t(4, 5), t1(4, 5);
    cin >> t;
    t[0][0] = 5;
    int x = t[2][3];
    t1 = t;
    cout << t << "\n"
         << t1;
}
