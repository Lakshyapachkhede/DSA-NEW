#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int temp[high-low+1];
    int left=low, right=mid+1, i=0;

    while (left <= mid && right <= high)
    {
        if(a[left] <= a[right])
        {
            temp[i++] = a[left++];
        }
        else 
        {
            temp[i++] = a[right++];
        }
    }

   

    while (left <= mid)
    {
        temp[i++] = a[left++];
    }

    while (right <= high)
    {
        temp[i++] = a[right++];
    }

    
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}

void mergeSort(int v[], int low, int high)
{
    if(low == high) return;
    int mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}



int main()
{
    int v[] = {222, 111, 99, 88 ,77 ,66, 23};
    // vector<int> v = {2, 1, 3 , 5, 6, 7};

    mergeSort(v, 0, 6);

    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}