#include<iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> a;
    vector<int> b(5); // initialized to 0
    vector<int> c = {1, 2, 3, 4};
    vector<int> d(5, 10); // {10, 10, 10, 10, 10};

    a.push_back(10); // add an element to end 
    a.push_back(20); // time complexity amortized O(1)
    a.push_back(30);  // rarely takes O(n) but mostly take O(1)


    a.pop_back(); // complexity O(1) does not return removed element

    int x = a.back(); // returns last element
    int y = a.front(); // returns first element


    //getting element
    cout << a[1] << '\n'; // does not perform bound checking
    cout << a.at(1) << '\n'; // perform bound checking


    cout << a.size() << '\n'; // number of elements
    cout << a.empty() << '\n'; // returns true if empty

    //iterating
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ';
    }
    
    cout << '\n';


    
    //copying takes time for large objects
    for (int i : a) // cannot update elements like i = 100
    {
        cout << i<< ' ';
        
    }
    cout << '\n';

    for(int &i: a) // can update elements
    {
        cout << i << ' ';

    }
    cout << '\n';

    // use for large objects example string
    for(const int &i: a) // read without copying 
    {
        cout << i << ' ';

    }
    cout << '\n';


    // capacity means how many elements can fit without resizing
    cout << a.capacity() << '\n';
    cout << a.size() << '\n';

    a.reserve(10);// i am going to insert 10 elements after some time reserve memeory so dont have to allocate it again and again
    a.resize(5); // chops off elements > n works as same some difference
    

    // insert 99 at index 2 O(n)
    a.insert(a.begin() + 2, 99);
    
    // removes element at index 2 O(n)
    a.erase(a.begin() + 2);

    // removes all elements
    a.clear();

    //It behaves differently internally from a normal vector<T> and uses bit-level packing.
    vector<bool> e;

    // 2d 
    vector<vector<int>> matrix;

    vector<vector<int>> mat2(3, vector<int>(4, 0));

    mat2[0][0] = 67;
    cout << mat2[0][0] << ' ';
    cout << mat2.at(0).at(0) << '\n';

    for (int i = 0; i < 5; i++)
    {
        a.push_back(i);
    }


    reverse(a.begin(), a.end());

    sort(a.begin(), a.end());

    auto it = min_element(a.begin(), a.end());

    cout << *it << '\n';










    return 0;
}