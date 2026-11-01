#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void twoSum(vector<int> a, int k)
{

    unordered_map<int,int> mp;

    for (int i = 0; i < a.size(); i++)
    {
        auto it = mp.find(k - a[i]);

        if (it != mp.end())
        {  
            cout << mp[k-a[i]] << ' ' << i << '\n';
            return;
        }

        mp[a[i]] = i;
    }
    
    
}


int main(){
    
    vector<int> a = {2,7,11,15};
    twoSum(a, 9);
    return 0;
}