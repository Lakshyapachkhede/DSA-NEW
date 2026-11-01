#include<iostream>
using namespace std;

int main(){
    
    // square pattern
    int n;
    cout << "Enter n: ";

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }

        cout << "\n";
    }
    
    return 0;
}