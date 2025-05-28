#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void ReverseArray(int arr[], int n)
{
    int temp[n];

    for(int i = 0; i<n; i++)
    {
        temp[i] = arr[n-i-1];
    }

    printArray(temp, n);
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    ReverseArray(arr, n);
    return 0;
}