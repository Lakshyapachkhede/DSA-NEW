#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v)
{

    for (int i = 1; i < v.size(); i++)
    {
        int j = i;   
        while (j > 0 && (v[j-1] > v[j]) )        
        {     
            int temp = v[j];
            v[j] = v[j-1];
            v[j-1] = temp;
            j--;
        }
    }
}



int main()
{
    vector<int> v = {222, 111, 99, 88 ,77 ,66, 23};
    // vector<int> v = {2, 1, 3 , 5, 6, 7};

    insertionSort(v);

    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}