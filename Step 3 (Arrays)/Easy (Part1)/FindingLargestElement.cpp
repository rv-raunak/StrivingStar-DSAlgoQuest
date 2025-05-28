#include<bits/stdc++.h>
using namespace std;

int Brute_Force(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n-1];

    //TC: O(nlog(n)) (because sort() function internally takes this time to sort)
    //SC: O(n)   (Considering we are using mergesort())
}

int Optimal_Approach(int arr[], int n)
{
    int max = arr[0];   //assumption
    for(int i = 0; i<n; i++)
    {
        if(max<arr[i]) max=arr[i];
    }
    return max;

    //TC : O(N)
    //SC: O(1)
}


int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements: ";
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    int max1 = Brute_Force(arr, n);
    cout<<"Maximum Element by Brute Approach: "<<max1<<endl;
    
    int max2 = Optimal_Approach(arr, n);
    cout<<"Maximum Element by Optimal Approach: "<<max2<<endl;



    return 0;
}