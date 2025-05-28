#include<bits/stdc++.h>
using namespace std;

//hint: this is the character hashing for lowercase letters only
//however, for only uppercase letters we can do "s[i]-'A'" 
//and for all the letters we can go for the array size of 256 (which is shown in CharacterHashing2.cpp)
int main()
{
    string s;
    cout<<"Enter String: ";
    cin>>s;

    //pre-computing
    int hash[26]={0};
    for(int i = 0; i<s.size(); i++)
    {
        hash[s[i]-'a']++;  //since subtraction is going on here so it is implicitly typecasted to its ascii integral value for calculation
    }
    //remember that by making hash array I don't only mean to assign the characters according to the corresponding index but also to compute the frequency and store it at the right index too
    //I wrote the above cuz I did this mistake, just look at the code below

                                        //Pre-computing 
                                        // int hash[26] = {0};   

                                        // int ch=97;
                                        // for(int i = 0; i<26; i++)
                                        // {
                                        //     hash[i] = ch;
                                        //     ch++;
                                        // }


                                        // for(int i  = 0; i<26; i++)
                                        // {
                                        //     cout<<'('<<(char)hash[i]<<' '<<i<<')'<<' ';
                                        // }
    //this code of mine is actually my first attempt to make a hash for the characters but it only assignes the alphabets to their corresponding indexes but doesn't store the frequency and doesn't even provide a mechanism to store the frequency of elements
    // by hashing we simply want to achieve that the element of the main array must be same as the index of hash arry and at that index its frequency should be stored as accessiong thorugh index only takes constant time which improves the time complexity by a lot.

    int q;
    cout<<"Enter The Number Of Times You Wanna Query The Array: ";
    cin>>q;
  
    cout<<"Enter Values You Wanna Query For: ";
    while(q--)
    {
        char c;
        cin>>c;
        cout<<c<<" has a frequency: "<<hash[c-'a']<<endl;    
    }

    return 0;
}
