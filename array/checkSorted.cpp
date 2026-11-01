#include<iostream>
using namespace std;

bool checkSorted(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if(a[i] > a[i+1]) return 0;
    }
    

    return 1;
}

int main(){
    
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {1, 2, 3, 5, 4};

    cout << checkSorted(a, 5) << '\n';
    cout << checkSorted(b, 5) << '\n';

    return 0;
}