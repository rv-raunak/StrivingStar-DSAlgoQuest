#include<bits/stdc++.h>
using namespace std;

bool checkArmstrong(int num)
{
    int numcopy = num, numcheck = num, len = 0, sum = 0;

    //finding the length
    while(num>0)
    {
        len++;
        num=num/10;
    }
    
    while(numcopy>0)
    {
        int lastdigit = numcopy%10;
        sum+=pow(lastdigit, len);
        numcopy/=10;
    }

    if(numcheck == sum) return true;
    return false;


}

int main()
{
    int num;
    cout<<"Enter the Number: ";
    cin>>num;
    
    if(checkArmstrong(num) == true) cout<<num<<" is an Armstrong Number";
    else cout<<num<<" is not an Armstrong Number";

    return 0;
}