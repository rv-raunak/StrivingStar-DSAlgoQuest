#include<bits/stdc++.h>
using namespace std;
//printing 1 to N numbers using recursion by backtracking
void printNo(int i, int N)
{
    if(i<1) return;     //base condition //termination condition
    printNo(i-1,N);
    cout<<i<<endl;
}

int main()
{
    int N;
    cout<<"Enter the range: ";
    cin>>N;
    printNo(N,N);
    return 0;
}