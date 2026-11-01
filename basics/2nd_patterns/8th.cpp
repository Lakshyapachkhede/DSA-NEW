#include<iostream>
using namespace std;

int main(){
    // reverse triangle pattern 

    int n;
    cout << "Enter n: ";

    cin >> n;

    for (int i = n; i > 0; i--)
    {

        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }


        for (int k = 0; k < i*2-1; k++)
        {
            cout << "*";
        }
        
        cout << '\n';
    }
    

    return 0;
}