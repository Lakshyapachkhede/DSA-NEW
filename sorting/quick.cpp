#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i <= high && a[i] <= pivot) i++;
        while (j >= low && a[j] > pivot) j--;

        if(i < j) swap(a[i], a[j]);      
    }

    swap(a[low], a[j]);
    
    return j;
}


void quickSort(int a[], int low, int high)
{

    if(low < high)
    {
        int pivotIdx = partition(a, low, high);
        quickSort(a,low, pivotIdx-1);
        quickSort(a, pivotIdx+1, high);
    }
}



int main()
{
    int a[] = {222, 111, 99, 88 ,77 ,66, 23};
    // vector<int> v = {2, 1, 3 , 5, 6, 7};

    quickSort(a,0, 6);

    for (auto i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}