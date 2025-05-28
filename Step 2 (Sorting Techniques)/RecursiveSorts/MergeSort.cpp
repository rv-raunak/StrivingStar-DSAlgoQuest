#include<bits/stdc++.h>
using namespace std;


void mergeArrays(vector<int>&arr, int low, int mid, int high)
{
    //defining the pointers
    int left = low;
    int right = mid+1;
    
    //making a temporary data structure to store the sorted values
    vector<int>temp;   //its empty initially
    
    //main checking condition
    while(left<=mid && right<=high)
    {
        if(arr[left]<arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i<=high; i++)
    {
        arr[i] = temp[i-low];
    }

}

void mergeSort(vector<int>&arr, int low, int high)
{
    //base condtion
    if(low==high) return;
    int mid = (low+high)/2;    //finding the middle index for splliting the array
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    mergeArrays(arr, low, mid, high);
}

int main()
{
    int num;
    cout<<"Enter Number: ";
    cin>>num;

    vector<int> arr(num);
    for(int i = 0; i<num; i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr, 0, arr.size()-1);
    
    for(auto x : arr) cout<<x<<" ";
    return 0;
}