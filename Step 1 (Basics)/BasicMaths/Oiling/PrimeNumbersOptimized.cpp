#include<bits/stdc++.h>
using namespace std;

//finding the prime numbers with optimised approach
void checkprime(int num)
{
    int count=0;
    for(int i = 1; i*i<=num; i++)
        {
            if(num % i == 0) 
            {
                count++;
                if(i!=(num/i)) count ++;
            }
        }

    if(count==2) cout<<num<<" is a prime number";
    else cout<<num<<" is not a prime number";
}

int main()
{
    int num; 
    cout<<"Enter the Number: ";
    cin>>num;
    checkprime(num);
    return 0;
}
