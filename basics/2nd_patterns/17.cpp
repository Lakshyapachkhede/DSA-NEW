#include<iostream>
using namespace std;

int main(){


    int n;
    cout << "Enter n: ";

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i -1; j++)
        {
            cout << " ";
        }

        for (int k = 0; k <= i; k++)
        {
            cout << (char)('A' + k);
        }

        for (int l = i; l > 0; l--)
        {
            cout << (char)('A' + l - 1);
       
        }
        
        
        cout << "\n";
    }
    

    return 0;
}