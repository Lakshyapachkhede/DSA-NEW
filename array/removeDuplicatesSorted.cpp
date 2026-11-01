#include<iostream>
using namespace std;

int removeDuplicates(int a[], int n)
{

    int placedIndex = 0;
    int j = 1;
    while (j < n)
    {   
        if(a[j] != a[placedIndex])
        {
            a[++placedIndex] = a[j];
        }
        
        j++;
    }
    

    return placedIndex+1;
}


int main(){
    
    int a[10] = {0,0,1,1,1,2,2,3,3,4};
    
    int n = removeDuplicates(a, 10);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';


    return 0;
}