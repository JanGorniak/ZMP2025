#include <iostream>

using namespace std;

int main()
{
    int szukana, dlugosc;
    cin >> szukana;
    cin >> dlugosc;
    int* tablica=new int[dlugosc];
    for(int i=0; i<dlugosc; ++i)
    {
        cin >> tablica[i];
    }

    for(int i=0; i<dlugosc; ++i)
    {
        if(tablica[i]==szukana)
        {
            cout << "tak " << i;
            return 0;
        }
    }
    cout << "nie";
    return 0;
}