#include <iostream>

using namespace std;

int max_diff(int arr[], int size)
{
    int maximum=0;
    for(int i=0; i<size;++i)
    {
        for(int j=i+1; j<size; ++j)
        {
            if(arr[i]-arr[j]>maximum)
            {
                maximum=arr[i]-arr[j];
            }
        }
    }
    return maximum;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i=0; i<size; ++i)
    {
        cin >> arr[i];
    }
    cout << max_diff(arr, size);
    return 0;
}