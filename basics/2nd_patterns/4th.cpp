#include<iostream>
using namespace std;

int main(){
    // left number triangle pattern 2

    int n;
    cout << "Enter n: ";

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1;
        }
        cout << "\n";
    }
    

    return 0;
}