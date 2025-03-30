#include <iostream>

using namespace std;

int main()
{
    int sekret[8], wiadomosc[8];
    for(int k=0;k<8;++k)
    {
        cin >> sekret[k];
    }
    for(int k=0;k<8;++k)
    {
        cin >> wiadomosc[k];
    }
    for(int k=0;k<8;++k)
    {
        cout << (sekret[k]^wiadomosc[k]);
    }
}