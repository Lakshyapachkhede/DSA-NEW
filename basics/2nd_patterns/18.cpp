#include<iostream>
using namespace std;

int main(){


    int n;
    cout << "Enter n: ";

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (char j = 'A' + n-1-i; j <= ('A' + n-1) ; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
    

    return 0;
}