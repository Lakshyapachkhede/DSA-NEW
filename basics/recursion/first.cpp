#include<iostream>
using namespace std;

void loop(int n)
{
    if(n == 0)
    {
        return;
    }

    cout << n << '\n';
    loop(n-1);
}


int main(){
    loop(5);
    return 0;
}