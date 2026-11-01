#include <iostream>
using namespace std;




int main()
{
    int n;
    cout << "Enter n: ";

    cin >> n;

    int j;
    for (int i = 0; i < n * 2 - 1; i++)
    {
        for (j = 0; j < n * 2 - 1; j++)
        {   
            int dis = min(min(i, (n*2-2) - i), min(j, (n*2-2) - j)); 
            cout << n-dis;

        }

        cout << '\n';
        
    }

    return 0;
}