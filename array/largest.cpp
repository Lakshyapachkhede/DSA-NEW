#include<iostream>
using namespace std;

int largest(int a[], int n)
{
    int maxIdx = 0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] > a[maxIdx])
        {
            maxIdx = i;
        }
    }

    return a[maxIdx];
}


int main(){
    
    int a[10] = {32, 31,5,11, 99, 121, 8982, 12, 112, 99};
   

    cout << largest(a, 10);


    return 0;
}