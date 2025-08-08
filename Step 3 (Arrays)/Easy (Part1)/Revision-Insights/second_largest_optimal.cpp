#include<iostream>
using namespace std;

int duplicateFrequency(int arr[], int size)
{
    int i = 0;
    for(int j = 0; j<size; j++)
    {

        //we can't apply this method if the elements are unsorted as this != condition will cause havos as the same value will be considered again and again by the pointer
        if(arr[j]!=arr[i])      
        {
            i++;
            arr[i]=arr[j];
        }
    }

    return (i+1);
}


int main()
{
    //getting the number of unique elements in an array

    int arr[] = {1,1,1,1,1,2,2,2,3,3,3,3,3};

    // int arr[] = {1,1,1,2,3,3,2,4,4,3,1};   
    //this approach won't work on this as the elements are unsorted (earlier I was gonna use this but then realised it can't be done directly through this method, this also teaches me a lesson although you might know the code very well still while typing by your own logical mind(without seeing the code just knowing the logic (not pseudo code) you get to realize the importance of some conditions and assumptions more intricately that you might have avoided/overlooked earlier)

    int len = sizeof(arr)/sizeof(arr[0]); //C++ doesn't have any in-built function to calculate length if array. size() works for STLs only and .length is only present in Java



    int num = duplicateFrequency(arr, len);

    cout<<"No. of Duplicate elements: "<<num<<endl;;
    for(int i = 0; i<num; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;



}