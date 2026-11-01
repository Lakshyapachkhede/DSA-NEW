#include <iostream>
using namespace std;

int gcd(int n1, int n2)
{
    for (int i = (n1 < n2 ? n1 : n2); i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
            return i;
        // cout << i << '\n';
    }

    return 1;
}

// Euclidean algorithm

int gcd2(int a, int b)
{

    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a<0?-a:a;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    cout << gcd2(n1, n2) << '\n';

    return 0;
}