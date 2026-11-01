#include <iostream>
#include <vector>

using namespace std;


void selectionSort(vector<int> &v)
{

    for (int i = 0; i < v.size()-1; i++)
    {
        int minIdx = i;
        for (int j = i+1; j < v.size(); j++)
        {
            if(v[j] < v[minIdx])
            {
                minIdx = j;
            }
        }

        int temp = v[i];
        v[i] = v[minIdx];
        v[minIdx] = temp;
    }
    

}



int main()
{
    vector<int> v = {32, 23, 1, 99,242, 223};

    selectionSort(v);

    for(auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}