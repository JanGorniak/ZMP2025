#include <iostream>

using namespace std;

void genSubset(int tablica[], int n, int i, int przechowywacz[], int rozmiar, int k)
{
    if(i==k)
    {
        for(int i = 0; i < rozmiar; ++i)
        {
            cout << przechowywacz[i] << " ";
        }
        cout << endl;
        return;
    }

    genSubset(tablica, n, i+1, przechowywacz, rozmiar, k);

    przechowywacz[rozmiar] = tablica[i];
    genSubset(tablica, n, i+1, przechowywacz, rozmiar+1, k);
}

int main()
{
    int n, k;
    cin >> n;
    int tablica[n], przechowywacz[n];
    for(int i=0; i<n; i++){
        cin >> tablica[i];
    }
    cin >> k;
    genSubset(tablica, n, 0, przechowywacz, 0, k);
    return 0;
}