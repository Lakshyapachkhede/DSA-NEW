#include<iostream>
using namespace std;

void reverseArray(int a[], int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int temp = a[start];
    a[start] = a[end];
    a[end] = temp;

    reverseArray(a, start+1, end-1);
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)

    {
    cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int a[6] = {1,2,3,4,5,6};

    reverseArray(a, 0, 5);

    printArray(a, 6);

    return 0;
}