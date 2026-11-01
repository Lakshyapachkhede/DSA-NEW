#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v)
{

    for (int i = 0; i < v.size() - 1; i++)
    {
        int didSwap = 0;
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;

                didSwap = 1;
            }
        }

        if(!didSwap) break;
    }


    
}



int main()
{
    // vector<int> v = {222, 111, 99, 88 ,77 ,66, 23};
    vector<int> v = {2, 1, 3 , 5, 6, 7};

    bubbleSort(v);

    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}