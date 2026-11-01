#include <iostream>
using namespace std;

int secondLargest(int a[], int n)
{
    int maxIdx = 0;
    int secondLargestI = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[maxIdx])
        {
            secondLargestI = maxIdx;
            maxIdx = i;
        }
        else if (a[i] > a[secondLargestI] && a[i] != a[maxIdx])
        {
            secondLargestI = i;
        }
    }

    return a[secondLargestI];
}

int main()
{

    int a[10] = {32, 31, 5, 11, 99, 121, 121, 12, 112, 99};

    cout << secondLargest(a, 10);

    return 0;
}