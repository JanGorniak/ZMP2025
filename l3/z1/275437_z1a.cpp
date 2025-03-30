#include <iostream>

using namespace std;

unsigned long long fib(int n)
{
    unsigned long long f1=1, f2=1, temp;

    if(n==1||n==0)
    {
        return 1;
    }
    else
    {
        for(int k=2; k<n; ++k)
    {
        temp=f2;
        f2=f2+f1;
        f1=temp;
    }
    return f2;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}