#include  <iostream>

using namespace std;

int n, dlugosc;

int main()
{
    cin >> n;
    cout << n << " ";
    while(n!=1)
        if(n%2==0)
        {
            n=n/2;
            cout << n <<" ";
            ++dlugosc;
        }
        else
        {
            n=3*n+1;
            cout << n <<"  ";
            ++dlugosc;
        }
    
    cout << ", " << dlugosc;
return 0;
}
