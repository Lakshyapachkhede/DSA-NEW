#include<iostream>
using namespace std;

bool checkPalindrome(int n)
{
    if (n < 0)
    {
        return 0;
    }
    int r = 0;
    int N = n;

    while (n != 0)
    {

        
        if(r > 214748364 || r < -214748364) return 0;
        
        int d = n % 10;
        r *= 10;
        r += d;
        n = n / 10;

    }

    return r==N;

}

int main(){
    
    int n;
    cin >> n;

    

    cout << checkPalindrome(n) << '\n';

    return 0;
}