//reversing an array through recursion using 1
#include<iostream>
using namespace std;

void revArray(int i, int n, int arr[])
{
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]); //in-built function to swap the values of the array
    revArray(i+1, n, arr);

}

int main()
{
    int size;
    cout<<"Enter the size of Array: ";
    cin>>size;

    int arr[size];

    //inputting the values in an array
    for(int i = 0; i<size; i++) cin>>arr[i];

    revArray(0, size, arr);
    
    //printing an array
    for(int i = 0; i<size; i++) cout<<arr[i]<<" ";  //remember that array is passed by reference so no need to return it back and not need to explcitly use '&' as well; 
    return 0;
}