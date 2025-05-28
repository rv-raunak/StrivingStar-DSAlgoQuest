#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Numbers: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    //pre-compute
    map<int, int> hashmap;
    for(int i=0; i<n; i++)
    {
        hashmap[arr[i]]++;  
        //its very beautiful btw since although we traversing the numbers and making them keys we are actually incrementing the corresponding values to those keys in order to keep their frequencies
    }

    int q;
    cout<<"Enter Query Count: ";
    cin>>q;

    cout<<"Enter Elements: ";
    while(q--)
    {
        int element;
        cin>>element;
        cout<<element<<" has a frequency: "<<hashmap[element]<<endl;
    }

    cout<<"<-------------------Just for map analysis purpose----------------->"<<"\n";
    for(auto x: hashmap){cout<<'('<<x.first<<" , "<<x.second<<')'<<endl;}

    return 0;
}
