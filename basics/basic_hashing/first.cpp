#include<iostream>
using namespace std;


void frequency(int a[], int n)
{
    int map[10] = {0};

    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if(map[i])
        {
            cout << i << ':' << map[i] << '\n';
        }
    }
    
    
}

int main(){
    int n = 5;

    int a[n] = {1,2,3,1,3};

    frequency(a, n);



    return 0;
}