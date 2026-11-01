#include <iostream>
#include <vector>
using namespace std;

vector<int> I(vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    vector<int> res;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }

    return res;
}

vector<int> I2(vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    vector<int> res;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            if (res.empty() || res.back() != a[i])
                res.push_back(a[i]);
            i++;
            j++;
        }
    }

    return res;
}

int main()
{

    vector<int> a = {1, 1, 2, 3, 4, 4, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};

    vector<int> c = I(a, b);
    // vector<int> c = I2(a, b);

    for (auto i : c)
    {
        cout << i << ' ';
    }

    cout << '\n';
    return 0;
}