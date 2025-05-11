#include <iostream>

using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i=left;
    int j=mid;
    int k=left;

    while (i<mid && j<right) {
        if (arr[i]<=arr[j]) {
            temp[k++]=arr[i++];
        } else {
            temp[k++]=arr[j++];
        }
    }

    while (i<mid) temp[k++]=arr[i++];
    while (j<right) temp[k++]=arr[j++];

    for (int i=left; i<right; ++i) {
        arr[i]=temp[i];
    }
}

void merge_od_dolu(int arr[], int n) {
    int* temp = new int[n];

    for (int width=1; width<n; width*=2) {
        for (int i=0; i<n; i+=2*width) {
            int left=i;
            int mid;
            if (i+width<n) {
                mid=i+width;
            } else {
                mid=n;
            }
            int right;
            if(i+2*width<n)
            {
                right=i+2*width;
            }
            else
            {
                right=n;
            }
            merge(arr, temp, left, mid, right);
        }
    }

    delete[] temp;
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

    merge_od_dolu(arr, size);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}