#include<bits/stdc++.h>
using namespace std;

int MaxElement(int arr[], int n, unordered_map<int, int>&hashmap)  //passing by reference costs much less than pass by value
{
    //finding the max frequency
    int maxf = 0;
    int maxElement=arr[0];
    for(int i = 0; i<n; i++)
    {
        if(hashmap[arr[i]]>maxf)
        {
            //galti-alert I forgot the first  ine so the maxf was not being updated and it was giving the wrong result, I did this mistake cuz I was too foused on the results
            maxf = hashmap[arr[i]];     
            maxElement=arr[i];
        }
    }

    return maxElement;

}


int MinElement(int arr[], int n, unordered_map<int, int>&hashmap)
{
    //finding the min frequency
    int minf = n;
    int minElement=arr[0];
    for(int i = 0; i<n; i++)
    {
        if(hashmap[arr[i]]<minf)
        {
            minf = hashmap[arr[i]];     
            minElement=arr[i];
        }
    }

    return minElement;

}



int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    int arr[n];  //main array
    unordered_map<int, int> hashmap;  //hash map

    cout<<"Enter Elements: ";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        hashmap[arr[i]]++;
        //input and pre-computation is done simultaneously (Although this doesn't affect the Time Complexity)
    }

    int Highest_Frequency_Element = MaxElement(arr, n, hashmap);
    int Lowest_Frequency_Element = MinElement(arr, n, hashmap);

    cout<<Highest_Frequency_Element<<" has the highest frequency of "<<hashmap[Highest_Frequency_Element]<<endl;
    cout<<Lowest_Frequency_Element<<" has the lowest frequency of "<<hashmap[Lowest_Frequency_Element]<<endl;

  
    return 0;
}