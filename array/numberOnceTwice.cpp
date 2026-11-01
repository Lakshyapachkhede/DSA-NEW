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


int onceNumber(int a[], int n)
{
    int x = 0;


    for (int i = 0; i < n; i++)
    {
        x ^= a[i];
    }

    return x;
    
}

int main(){
    int a[9] = {1,2,2,1,3,4,4,3,5};
    cout << onceNumber(a, 9);

    
    return 0;
}