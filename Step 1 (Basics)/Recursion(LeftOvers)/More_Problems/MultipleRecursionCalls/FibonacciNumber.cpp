//multiple recursion calls
#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n<=1) return n;
    int last = fib(n-1);
    int slast = fib(n-2);
    return last + slast;
}

int main()
{
    int num;
    cout<<"Enter the Nth Position: ";
    cin>>num;

    cout<<fib(num);
    return 0;
}