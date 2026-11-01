#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    vector<int> v = {32, 89, 232, 5254, 21123};

    // O(n log n).
    sort(v.begin(), v.end());

    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // descending
    sort(v.begin(), v.end(), greater<int>());
    sort(v.rbegin(), v.rend());

    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';

    cout << min(1, 2) << ' ';
    cout << max(1, 2) << ' ';

    cout << min({1, 2, 3, 4, 5}) << ' ';
    cout << max({1, 2, 3, 4, 5}) << ' ';

    cout << '\n';


    // custom sorting 
    // sorting according to second
    vector<pair<int, int>> a;
    a.push_back(pair<int, int>(1, 2));
    a.push_back(pair<int, int>(7, 8));
    a.push_back(pair<int, int>(2, 1));

    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    

    for (auto i : a)
    {
        cout << i.first << ' ' << i.second << '\n';
    }


    reverse(v.begin(), v.end());

    int d = 32;
    int b = 12;
    swap(d, b);

    cout << d << " " << b << '\n';

    // iterators

    //iterators are like pointers represents position in a container
    auto it = v.begin();

    cout << *it << '\n';
    it++;
    cout << *it << '\n';

    //v.end(); points to one position after the last element


    auto it2 = find(v.begin(), v.end(), 32); // O(N)

    if(it2 != v.end())
    {
        cout << "Found " << *it2 << '\n';
    }
    else 
    {
        cout << "Not found" << '\n';
    }
    
    bool found = binary_search(v.begin(), v.end(), 232); 
    cout << found << '\n';




    return 0;
}