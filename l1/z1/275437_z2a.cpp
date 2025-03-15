#include <iostream>

using namespace std;

int n, k=1, wielkosc=0;

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

int main()
{
    cin >> n;
    while(k<=n)
    {
        euklides(k,n);
        if(euklides(k,n)==1)
        {
            ++wielkosc;
            ++k;
        }
        else
        {
            ++k;
        }
    }
    cout << wielkosc << euklides(1,1);
    return 0;
}