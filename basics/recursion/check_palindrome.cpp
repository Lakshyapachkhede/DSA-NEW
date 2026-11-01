#include<iostream>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    if(i >= j)
    {
        return true;
    }

    return s[i] == s[j] && checkPalindrome(s, i + 1, j - 1);   
    
}


int main(){

    string s = "racecar";
    cout << checkPalindrome(s, 0, s.length() -1);

    return 0;
}