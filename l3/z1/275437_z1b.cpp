#include <iostream>

using namespace std;

unsigned long long good_fib(int n, int fib_a=0, int fib_b=1)
{
    if(n==0)
    {
        return fib_a;
    }
    else
    {
        return good_fib(n-1, fib_b, fib_a+fib_b);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << good_fib(n);
    return 0;
}