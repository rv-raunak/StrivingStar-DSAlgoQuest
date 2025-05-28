#include<iostream>
using namespace std;

int main()
{
    int num,constRev, rev=0;
    cout<<"Enter the Number: ";
    cin>>num;

    constRev=num;

    while(num>0)
    {
        int lastDigit=num % 10;
        num=num/10;
        rev=rev*10+lastDigit;
    }

    if(rev==constRev) cout<<constRev<<" is a palindrome";
    else cout<<constRev<<" is not a palindrome";
    return 0; 
}