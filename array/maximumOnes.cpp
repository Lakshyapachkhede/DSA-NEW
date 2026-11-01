#include<iostream>
using namespace std;

int maximumOnce(int a[], int n)
{

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;

        while (i < n && a[i])
        {
            count++;

            i++;
        }
        
        max = max>count?max:count;
    }
    

    return max;

}

int maximumOnce2(int a[], int n)
{
    int max = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == 1)
        {
            count++;
            max = max>count?max:count;

        }
        else 
        {
            count = 0;
        }
    }

    return max;

    
}

// both O(n)

int main(){
    
    int a[6] = {1,0,1,1,0,1};
    cout << maximumOnce2(a, 6);

    return 0;
}