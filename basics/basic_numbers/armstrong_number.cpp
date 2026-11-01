#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n < 0)
    {
        cout << 0 << '\n';
        return 0;
    }


    int x = n;
    int count = 0;
    while (x != 0)
    {
        count++;
        x/=10;
    }

    x = n;
    int sum = 0;
    while (x != 0)
    {
        int digit = x % 10;
        int c = 1;

        for (int i = 1; i <= count; i++)
        {
            c *= digit;
            
        }

        sum += c;
    
        x /= 10;
    }
    

    cout << (n == sum) << '\n';



    return 0;
}