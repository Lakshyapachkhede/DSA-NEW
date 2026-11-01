#include<iostream>
using namespace std;

int fibonacci(int n)
{   

    if(n == 1 || n == 0)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}


int main(){
    int n;
    cin >> n;
    cout << fibonacci(n) << '\n';
    return 0;
}

//0,1,1,2,3,5,