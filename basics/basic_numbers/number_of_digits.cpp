#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 0)
    {
        cout << "Number of digits: 0" << '\n';
        return 0;
    }

    if(n < 0)
    {
        n = -n;
    }

    int count = 0;
    while (n > 0)
    {
        count++;
        n/=10;
    }
    
    cout << "Number of digits: " << count << '\n';

    return 0;
}