#include<iostream>
using namespace std;

int missingNumber(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    int sumN = (n) * (n +1 ) /2;

    return sumN-sum;
    
}


int missingNumber2(int a[], int n)
{
    int x = n;


    for (int i = 0; i < n; i++)
    {
        x ^= i;
        x ^= a[i];
    }

    return x;
    
}

int main(){
    int a[10] = {0, 1, 8, 9, 10, 7, 2, 4, 3, 6};
    cout << missingNumber2(a, 10);

    
    return 0;
}