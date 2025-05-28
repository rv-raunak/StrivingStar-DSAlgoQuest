#include<bits/stdc++.h>
using namespace std;
//this is more optimised as we need only one argument and the other argument of 'N' was actually redundant 
//printing 1 to N numbers using recursion by backtracking
void printNo(int i)
{
    if(i<1) return;     //base condition //termination condition
    printNo(i-1);
    cout<<i<<endl;
}

int main()
{
    int N;
    cout<<"Enter the range: ";
    cin>>N;
    printNo(N);
    return 0;
}