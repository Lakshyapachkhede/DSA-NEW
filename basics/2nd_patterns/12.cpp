#include<iostream>
using namespace std;

int main(){

    // crown pattern

    int n;
    cout << "Enter n: ";

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        
        for (int j = 1; j <= i; j++)
        {
            cout << j;
       
        }

        for (int k = 0; k < (n-i)*2; k++)
        {
            cout << ' ';
        }

        for (int l = i; l > 0; l--)
        {
            cout << l;
       
        }
        

        cout << "\n";
    }
    

    return 0;
}