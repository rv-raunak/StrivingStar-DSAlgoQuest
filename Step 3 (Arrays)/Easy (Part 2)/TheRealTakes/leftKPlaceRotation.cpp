#include<bits/stdc++.h>
using namespace std;

void leftRotateArray(int arr[], int n, int d)
{
    d=d%n; //figuring out the actual rotations

    //creating and fillng the temp array with the main rotation chunk elements
    int temp[d];
    for(int i = 0; i<d; i++)
    {
        temp[i] = arr[i];
    }

    //shifting the leftover elements
    for(int i = d; i<n; i++)  //here the leftover elements starts from dth index
    {
        arr[i-d] = arr[i];
    }

    //putting back the elements to the new places from the temp array
    for(int i = n-d; i<n; i++)
    {
        arr[i] = temp[i-(n-d)];
    }
}


void leftRotateOptimal(int arr[], int n, int d)
{
    //Using the Reversal method (Or 3 times reversal method)

    d = d % n; // Handle cases where d > n
    if (d == 0) return; // No rotation needed
    reverse(arr, arr+d); //reversing the main chunk part
    reverse(arr+d, arr+n); //reversing the leftover chunk
    reverse(arr, arr+n); //reversing the whole array
}


int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"No. of times you wanna rotate the array: ";
    cin>>k;

    //leftRotateArray(arr, n, k);
    leftRotateOptimal(arr, n, k);
    for(auto i: arr){cout<<i<<" ";}
    return 0; 
}