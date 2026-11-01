#include <iostream>
#include <vector>
using namespace std;

void rotateLeftByOne(int a[], int n)
{
    int temp = a[0];

    for (int i = 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }

    a[n - 1] = temp;
}
void rotateLeftByDBrute(int a[], int n, int d)
{
    d = d % n;

    vector<int> v;

    for (int i = 0; i < d; i++)
    {
        v.push_back(a[i]);
    }

    for (int i = d; i < n; i++)
    {
        a[i - d] = a[i];
    }

    for (int i = n - d; i < n; i++)
    {
        a[i] = v[i - (n - d)];
    }
}

void reverseArray(int a[], int low, int high)
{
    int i = low, j = high;
    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        j--;
        i++;
    }
}

void rotateArrayLeftByDOptimal(int a[], int n, int d)
{
    d = d % n;
    reverseArray(a, 0, d - 1);
    reverseArray(a, d, n - 1);
    reverseArray(a, 0, n - 1);
}

void rotateArrayRightByDOptimal(int a[], int n, int d)
{
    d = d % n;
    reverseArray(a, 0, n - 1);
    reverseArray(a, 0, d - 1);
    reverseArray(a, d, n - 1);
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

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // rotateLeftByOne(a, 10);
    // rotateLeftByDBrute(a, 10, 3);
    // rotateArrayLeftByDOptimal(a, 10, 3);
    rotateArrayRightByDOptimal(a, 10, 3);
    // reverseArray(a, 10);
    printArray(a, 10);

    return 0;
}