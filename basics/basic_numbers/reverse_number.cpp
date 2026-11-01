//https://leetcode.com/problems/reverse-integer/
#include<iostream>
#include <limits>
using namespace std;


bool checkSafe(int a, int d)
{   

    if(a > 0)
    {
        if(a > INT_MAX / 10 || (a == INT_MAX / 10 && d > INT_MAX % 10))
        {
            return 0;
        }
    }
    else
    {
        if(a < INT_MIN / 10 || (a == INT_MIN / 10 && d > INT_MIN % 10))
        {
            return 0;
        }
    }

    return 1;
}

int getReverse(int n)
{
    int r = 0;

    while (n != 0)
    {

        int d = n % 10;
        // if(!checkSafe(r, d)) return 0;
        if(r > 214748364 || r < -214748364) return 0;
        r *= 10;
        r += d;
        n = n / 10;

    }

    return r;

}

int main(){
    int n;
    cin >> n;

    

    cout << getReverse(n) << '\n';


    return 0;
}