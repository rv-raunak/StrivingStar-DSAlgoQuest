#include<bits/stdc++.h>
using namespace std;


//this is a much better to do character hashing as it can check the frequency of all the characters 

//and since the array size is 256 only and cannot exceed that as 256 is the max number of characters we have to we don't suffer any limitations or problem with the array size declaration unlike int and boolean values (where max. size can be any). So, we can without any hesitation use array for character hashing
int main()
{
    string s;
    cout<<"Enter String: ";
    cin>>s;

    //pre-computing
    int hash[256]={0};
    for(int i = 0; i<s.size(); i++)
    {
        hash[s[i]]++;  
        //here, although s[i] is a character but it auto-casts itself as an integer (i.e. its ascii value) since we can have only integer as index values
    }

    int q;
    cout<<"Enter The Number Of Times You Wanna Query The Array: ";
    cin>>q;
  
    cout<<"Enter Values You Wanna Query For: ";
    while(q--)
    {
        char c;
        cin>>c;
        cout<<c<<" has a frequency: "<<hash[c]<<endl;    
    }

    return 0;
}
