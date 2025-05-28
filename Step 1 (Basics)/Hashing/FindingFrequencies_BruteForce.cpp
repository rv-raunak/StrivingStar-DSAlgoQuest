#include<iostream>
using namespace std;
//Given an array find the frequencies of the asked(queried) elements
int countElement(int element, int arr[], int n)
{
    int counter=0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == element) counter++;
    }
    return counter;
}

int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int q;
    cout<<"Enter the Number of Queries you wanna ask: ";
    cin>>q;

    cout<<"Enter the Elements to check their frequency: ";

    //its a greater way to fetch elements as we can input values one by one and also by all at once
    while(q--)
    {
        int number; 
        cin>>number;
        cout<<number<<" has a frequency of: "<<countElement(number, arr, n)<<endl;
    }


    return 0;
}