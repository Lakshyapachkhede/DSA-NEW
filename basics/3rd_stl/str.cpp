#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "Hello";

    cout << s[0] << '\n';
    cout << s.size() << '\n';

    s.push_back('L');
    s.pop_back();

    //index , length
    string t = s.substr(1, 2);

    cout << t << '\n';
    cout << s.front() << '\n';
    cout << s.back() << '\n';
    cout << s.empty() << '\n';
    s.clear();

    string a = "Hello";
    string b = " World";
    string c = a + b;
    cout << c << '\n';

    s.append("Ram");

    if(s.find("abc") != string::npos)
    {
        cout << "Found" << '\n';
    }
    else 
    {
        cout << "Not Found" << '\n';
    }



    return 0;
}