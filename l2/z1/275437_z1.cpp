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

int multi_euklides(int x, int liczby[])
{
    int nwd=liczby[0];
    for (int i = 0; i < x; ++i) {
        nwd = euklides(nwd, liczby[i]);
    }
    return nwd;
}

int main()
{
    int dlugosc;
    cin >> dlugosc;
    int* liczby=new int[dlugosc];
    for(int i=0; i<dlugosc; ++i)
    {
        cin >> liczby[i];
    }
    cout << multi_euklides(dlugosc, liczby);
    return 0;
}