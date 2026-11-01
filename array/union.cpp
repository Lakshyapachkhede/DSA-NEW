#include <iostream>
#include <vector>
using namespace std;

vector<int> U(vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    vector<int> res;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            if (res.empty() || a[i] != res.back())
                res.push_back(a[i]);

            i++;
        }
        else
        {
            if (res.empty() || b[j] == res.back())
                res.push_back(b[j++]);

            j++;
        }
    }

    while (i < a.size())
    {
        if (res.empty() || a[i] != res.back())
            res.push_back(a[i]);
        i++;
    }

    while (j < b.size())
    {
        if (res.empty() || b[j] != res.back())
            res.push_back(b[j]);
        j++;
    }

    return res;
}

int main()
{

    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};

    vector<int> c = U(a, b);

    for (auto i : c)
    {
        cout << i << ' ';
    }

    cout << '\n';
    return 0;
}