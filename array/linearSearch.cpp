#include<iostream>
using namespace std;

int linearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if(a[i] == x) return i;
    }

    return -1;
}


int main(){
    
    int a[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    cout << linearSearch(a, 10, 3) << '\n';
    cout << linearSearch(a, 10, 69) << '\n';

    return 0;
}