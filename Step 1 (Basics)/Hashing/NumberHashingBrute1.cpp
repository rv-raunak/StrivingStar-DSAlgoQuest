#include<bits/stdc++.h>
using namespace std;

int frequency(int num, int arr[], int len)
{
    int count = 0;
    for(int i = 0; i<len; i++)
    {
        if(num == arr[i]) count++;
    }
    return count;
}


int main()
{
    cout<<"\n\n-----------------Entering the main sequence array------------------"<<endl;
    int n;
    cout<<"Enter Size: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }


    cout<<"\n\n-----------------Entering the query sequence------------------"<<endl;
    vector<int> query;
    char choice = 'y';

    int i = 1, element;
    while(choice == 'y')
    {
        cout<<"Element "<<i<<": ";
        cin>>element;
        query.push_back(element);
        i++;

        cout<<"Add further?(y/n): ";
        cin>>choice;
        if(choice != 'y') break;
    }


    cout<<"\n\nQuery Sequence Vector: ";
    for(auto i : query){cout<<i<<" ";}


    cout<<"\n\nCount Mapping for Each Query\n";
    for(int i = 0; i<query.size(); i++)
    {
        cout<<query[i]<<" : "<<frequency(query[i], arr, n)<<endl;
    }

    return 0;
}