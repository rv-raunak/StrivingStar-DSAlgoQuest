#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> &arr)
{
    int len = arr.size();
    int temp = arr[0];  //holds the first element

    for(int i = 1; i<len; i++)   //index starts from 1
    {
        arr[i-1] = arr[i];
    }

    arr[len-1] = temp;  //Galti-Alert: I was mistakenly doing arr[len] instead of len-1 due to my for loop instinct
    return arr;
}

//rotating array by 1 place 
int main()
{
    int element,num;
    vector<int> arr;

    cout<<"Enter size: ";
    cin>>num;

    for(int i = 0; i<num; i++)
    {
        cin>>element;
        arr.push_back(element);
    }

    for(auto i: rotateArray(arr)){cout<<i<<" ";}  //this also gives a deeper insight of usage of returning vector through a function
    return 0;
}