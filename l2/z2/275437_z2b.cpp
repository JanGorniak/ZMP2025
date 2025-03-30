#include <iostream>

using namespace std;

int binary_search(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}


int main()
{
    int dlugosc, szukana, n;
    cin >> dlugosc;
    cin >> szukana;
    int arr[dlugosc];
    for(int i=0; i<dlugosc; ++i)
    {
        cin >> arr[i];
    }
    n=binary_search(arr, 0, dlugosc-1, szukana);
    if(n==-1)
    {
        cout << "nie ";
    }
    else{
        cout << "tak " << n;
    }
    return 0;
}