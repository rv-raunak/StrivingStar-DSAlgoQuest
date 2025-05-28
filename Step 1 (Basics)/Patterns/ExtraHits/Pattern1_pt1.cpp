
#include<iostream>
using namespace std;

void pattern(int n)
{
    int freq=0;
    int diff=1;                   //for the odd difference b/w the numbers
    int first=1;
    for(int i = 1; i<=n; i++)
    {
        int num=first;           //setting the first value according to the frequency
        for(int j = 1; j<=i; j++)
        {
            cout<<num<<" ";
            num+=2;
        }
        cout<<endl;

        freq++;                 //frequency acts like a counter here which gets reset after every 2 rows
        if(freq<=2)
        {
            diff+=0;            //if the freq is not more than 2 then this means that the same differnce has to be added
            first+=diff;
        }
        else{
                                //if the freq exceeds 2 then this means that 2 rows are skipped, so now we can increment the difference by 2
            diff+=2;            //since first value of diff=1 therefore adding 2 to it everytime will generate an odd sequence 1,3,5
            first+=diff; 
            freq=1;             //after the every 2 rows freq is reset 
        }

    }
}

int main()
{
    int num;
    cout<<"Enter Number: ";
    cin>>num;

    pattern(num);
    
    return 0;
}