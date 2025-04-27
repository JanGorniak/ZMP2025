#include <iostream>

using namespace std;

int inwerjse(int arr[], int size)
{
    int inwersje=0;
    for(int i=0; i<size;++i)
    {
        for(int j=i+1; j<size; ++j)
        {
            if(arr[i]>arr[j])
            {
                ++inwersje;
            }
        }
    }
    return inwersje;
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
    cout << inwerjse(arr, size);
    return 0;
}