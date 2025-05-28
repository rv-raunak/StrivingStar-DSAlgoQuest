//this is my way of parameterised functional approach for recursion
#include<bits/stdc++.h>
using namespace std;

void Sum(int i, int n, int sum=0)
{
    if(i>n)
    {
        cout<<sum;
        return;
    }
    Sum(i+1, n, sum+i);
}

int main()
{
    int num;
    cout<<"Enter Number for the sum: ";
    cin>>num;

    Sum(0, num);

    return 0;
}