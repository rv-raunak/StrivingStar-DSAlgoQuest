#include<bits/stdc++.h>
using namespace std;

int BruteForce_Approach(int arr[], int n)
{
    set<int> temp;
    for(int i = 0; i<n; i++)
    {
        temp.insert(arr[i]);
    }


    //fetching the elements from the set and placing them back in the same array
    int index = 0;
    for(auto unique_element: temp)
    {
        arr[index] = unique_element;
        index++;
    }

    return index;  //since its already (last_element Index + 1)

}


int Optimal_Approach(int arr[], int n)
{
    int i = 0;  //i pointer setted at the first element by default
    for(int j = 1; j<n; j++)    //j pointer traversing the whole array  //can even start from 0 but it won't matter
    {
        if(arr[j]!=arr[i])   //condition for the new unique element(as its not equivalent to the previous unique element)
        {
            arr[i+1] = arr[j];   //moves the new unique element to the index postion next to the previous unique element
            i++;                 // i pointer itself moves to the same index position after the new unique elment is placed there
        }
    }
    return (i+1);         //this gives the size of the unique array (or the no. of unique elements)
}

int main()
{

    //I could have taken input for arrays just like my other programs but I wnated to test out the new way to find the number of elements though sizeof() function.

    int arr1[]={1,1,2,2,3,3,3};
    int arr2[]={1,1,2,2,3,3,3};
    //I made two exact copies since both the approach modify the same array

    //new way of finding the number of elements in an array
    int n =  sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Size of Array: "<<sizeof(arr1)<<" Bytes"<<endl;
    cout<<"Size of one element: "<<sizeof(arr1[0])<<" Bytes"<<endl;
    cout<<"No. of Elements: "<<n<<"\n\n\n";   //great way of quick-spacing 


    int uniqueElements = BruteForce_Approach(arr1, n);
    cout<<"No. of unique elements in the array (by Brute Force Approach): "<<uniqueElements<<endl;
    
    int uniqueElements2 = Optimal_Approach(arr2, n);
    cout<<"No. of unique elements in the array (by Optimal Approach): "<<uniqueElements2<<endl;
    

    return 0;
}