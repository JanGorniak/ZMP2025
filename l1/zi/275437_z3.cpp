#include <iostream>

using namespace std;

int main()
{
    int n, liczba_piatek=0;
    cin >> n;
    while(n>=5){
        n=n/5;
        liczba_piatek+=n;

    }
    cout << liczba_piatek;
    return 0;
}