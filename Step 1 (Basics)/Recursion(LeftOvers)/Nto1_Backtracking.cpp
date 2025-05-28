#include<bits/stdc++.h>
using namespace std;
//printing N to 1 numbers using recursion by backtracking
void printNo(int i, int N)
{
    if(i>N) return;
    printNo(i+1,N);
    cout<<i<<endl;
}

int main()
{
    int N;
    cout<<"Enter the range: ";
    cin>>N;
    printNo(1,N);
    return 0;
}