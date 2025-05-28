#include<bits/stdc++.h>
using namespace std;

int Sum(int n)
{
    if(n==0) return 0; 
    return n+Sum(n-1);   //here second return statement is very important too //otherwise you will just be getting 0 back
}
int main()
{
    int num;
    cout<<"Enter Number For Sum: ";
    cin>>num;

    cout<<Sum(num);
    return 0;
}