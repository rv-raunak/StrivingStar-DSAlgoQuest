#include<bits/stdc++.h>
using namespace std;

void RecursiveBubbleSort(int arr[], int n)
{
    if(n==0) return;
    int i = n-1;
    for(int j = 0; j<=i-1; j++)   //I could have made a recursive function for this too (refer LoopsVsRecursion Nested Loops using Recursion)
    {
        if(arr[j+1]<arr[j]) swap(arr[j+1], arr[j]);
    }
    RecursiveBubbleSort(arr, n-1);
}

void OGBubbleSort(int arr[], int n)
{
    for(int i = n-1; i>=0; i--)
    {
        for(int j = 0; j<=i; j++)
        {
            if(arr[j+1]<arr[j]) swap(arr[j+1], arr[j]);
        }
    }
}


int main()
{
    int size;
    cout<<"Enter Size: ";
    cin>>size;

    int arr[size];
    for(int i = 0; i<=size-1; i++) cin>>arr[i];
    
    //OGBubbleSort2(arr, size);
    RecursiveBubbleSort(arr, size);
    for(int x: arr) cout<<x<<" ";
    return 0;
}