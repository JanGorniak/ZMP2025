#include <iostream>

using namespace std;

long long merge(int arr[], int temp[], int left, int mid, int right)
{
    int inwersje=0, i=left, j=mid, k=left;

    while(i<mid && j<right)
    {
        if (arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inwersje+=mid-i;
        }
    }

    while(i<mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<right)
    {
        temp[k++]=arr[j++];
    }

    for(int i=left; i<right; ++i)
    {
        arr[i]=temp[i];
    }

    return inwersje;
}

int merge_sort(int arr[], int temp[], int left, int right)
{
    int inwersje = 0;
    if (right-left>1)
    {
        int mid=(left+right)/2;
        inwersje+=merge_sort(arr, temp, left, mid);
        inwersje+=merge_sort(arr, temp, mid, right);
        inwersje+=merge(arr, temp, left, mid, right);
    }
    return inwersje;
}

int zliczanie(int arr[], int n)
{
    int* temp=new int[n];
    int result=merge_sort(arr, temp, 0, n);
    delete[] temp;
    return result;
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for(int i=0; i<size; ++i)
    {
        cin >> arr[i];
    }
    cout << zliczanie(arr, size);

    return 0;
}
