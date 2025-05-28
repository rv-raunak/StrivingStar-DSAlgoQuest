#include<bits/stdc++.h>
using namespace std;

void brute_force(int arr[], int n, int turns)
{
    int temp_arr[n];
    for(int i = 0; i<n; i++)
    {
        //index calculation
        int rindex;
        if((i+turns)<n) 
        {
            rindex = i+turns;
        }
        else
        {
            rindex = (i+turns) - n;
            while(!(rindex>=0 && rindex<n))
            {
                rindex = rindex - n;
            }
        }

        temp_arr[rindex] = arr[i]; 

    }

    for(int x: temp_arr){cout<<x<<" ";} 
}
void brute_force2(int arr[], int n)
{
    int temp_arr[n];
    for(int i = 0; i<n; i++)
    {
        if(i==0){
            temp_arr[n-1]=arr[0];
        }
        if(i==n-1)
        {
            temp_arr[0] = arr[n-1];
            break;
        }
    
        temp_arr[i+1] = arr[i];
    }

    for(int x: temp_arr){cout<<x<<" ";}
 }

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements: ";
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    brute_force(arr, n, 1);
    cout<<endl;

    brute_force(arr, n, 2);
    cout<<endl;

    brute_force(arr, n, 3);
    cout<<endl;

    brute_force(arr, n, 4);
    cout<<endl;

    brute_force(arr, n, 5);
    cout<<endl;

    brute_force(arr, n, 6);
    cout<<endl;
    brute_force(arr, n, 19);
   

    return 0;
}