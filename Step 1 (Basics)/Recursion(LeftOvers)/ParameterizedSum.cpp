#include<bits/stdc++.h>
using namespace std;

void Sum(int n, int sum = 0)
{
    if(n<0)
    {
        cout<<sum;
        return;
    }
    Sum(n-1, sum+n);
}

int main()
{
    int num;
    cout<<"Enter Number for the sum: ";
    cin>>num;

    Sum(num, 0);

    return 0;
}