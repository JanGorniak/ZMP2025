#include <iostream>

using namespace std;

void genSubset(int tablica[], int n, int i, int przechowywacz[], int rozmiar)
{
    if(i==n)
    {
        for(int i = 0; i < rozmiar; ++i)
        {
            cout << przechowywacz[i] << " ";
        }
        cout << endl;
        return;
    }

    genSubset(tablica, n, i+1, przechowywacz, rozmiar);

    przechowywacz[rozmiar] = tablica[i];
    genSubset(tablica, n, i+1, przechowywacz, rozmiar+1);
}

int main()
{
    int n;
    cin >> n;
    int tablica[n], przechowywacz[n];
    for(int i=0; i<n; i++){
        cin >> tablica[i];
    }
    genSubset(tablica, n, 0, przechowywacz, 0);
    return 0;
}