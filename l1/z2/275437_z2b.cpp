#include <iostream>

using namespace std;

int euklides(int x, int y)
{
    int temp;
    while(y!=0)
    {
        temp=y;
        y=x%y;
        x=temp;
    }

    return x;
}

int euler(int x)
{
    int wielkosc=0, k=1;
    while(k<=x)
    {
        if(euklides(k,x)==1)
        {
            ++wielkosc;
            ++k;
        }
        else
        {
            ++k;
        }
    }
    return wielkosc;
}

int main()
{
    int funkcja=0, n, k=1;
    cin >> n;
    while(k<=n)
    {
        if(n%k==0)
        {
            funkcja+=euler(k);
            ++k;
        }
        else
        {
            ++k;
        }
    }
    cout << funkcja;
    return 0;
}