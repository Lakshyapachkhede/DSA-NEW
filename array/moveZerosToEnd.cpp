#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int moveZerosToEnd(int a[], int n)
{
    int lastPlaced = -1;

    int i = 0;
    while (i < n)
    {
        if (a[i] != 0)
        {
            swap(a[++lastPlaced], a[i]);
        }
        i++;
    }

    return lastPlaced + 1;
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main()
{

    // int a[] = {0,0,0,0,0,0,0,0,0,0};
    int a[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = sizeof(a) / sizeof(a[0]);

    n = moveZerosToEnd(a, n);
    printArray(a, 10);

    return 0;
}