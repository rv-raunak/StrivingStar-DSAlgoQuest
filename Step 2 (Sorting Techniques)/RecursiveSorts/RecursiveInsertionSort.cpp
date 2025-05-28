#include<bits/stdc++.h>
using namespace std;

void OG_Insertion_Sort(int arr[], int n)
{
    for(int i = 0; i<=n-1; i++)
    {
        int j = i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j], arr[j-1]);  //shifting the larger element to right while we are traversing from the left
            j--;
        }
    }
}

void Recursive_InsertionSort(int arr[], int n, int i = 0)
{
    //base condition
    if(i==n) return;

    int j = i;
    while(j>0 && arr[j-1]>arr[j])
    {
        swap(arr[j], arr[j-1]);  //shifting the larger element to right while we are traversing from the left
        j--;
    }

    Recursive_InsertionSort(arr, n, i+1);
}


int main()
{
    int num;
    cout<<"Enter Size: ";
    cin>>num;

    int arr[num];
    for(int i = 0; i<num; i++)
    {
        cin>>arr[i];
    }

    //OG_Insertion_Sort(arr, num);
    Recursive_InsertionSort(arr, num);
    for(int x: arr){cout<<x<<" ";}
    return 0;
}