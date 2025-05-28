#include <bits/stdc++.h>
using namespace std;

void Selection_Sort(int arr[], int n)
{
    for(int i = 0; i<=n-2; i++)
    {
        int mini = i;
        for(int j = i; j<=n-1; j++)
        {
            if(arr[j]<arr[mini]) mini=j; //min index is updated
        }

        //swapping
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
        
    }
}


void Bubble_Sort(int arr[], int n)
{
    int didSwap = 0; //in nb it is put inside the outer loop but it can be put here too
    for(int i = n-1; i>=0; i--)
    {
        for(int j = 0; j<=i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                //swapping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break; //this the optimization for the best case 
    }
}

void Insertion_Sort(int arr[], int n)
{
    for(int i = 0; i<=n-1; i++)
    {
        int j = i;
        while(j>0 && arr[j-1]>arr[j])
        {
            //swap
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j--;
        }
    }
}

int main()
{
    int num;
    cout<<"Enter Size: ";
    cin>>num;

    int arr[num];
    for(int i = 0; i<num; i++) cin>>arr[i];
    

    //arrays are by default passed by refernce so need to mention the symbol explicitly
    //Selection_Sort(arr, num);

    //Bubble_Sort(arr, num);

    Insertion_Sort(arr,num);
    
    for(int x: arr) cout<<x<<" ";
    return 0;
}