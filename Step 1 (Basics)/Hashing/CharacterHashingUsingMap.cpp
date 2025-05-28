#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout<<"Enter String: ";
    cin>>str;

    unordered_map<char, int> hashmap;   //char->letter & int-frequency

    //pre-compute
    for(int i = 0; i<str.size(); i++)
    {
        hashmap[str[i]]++;        //here the char will not be typecasted to int value and will be directly taken
    }
    
    int q;
    cout<<"Enter Query Size: ";
    cin>>q;

    cout<<"Enter Letters: ";
    while(q--)
    {
        char letter;  //Galti-Alert: I wrote 'int' instead of 'char' and thus it was not able to find the value(So beware silly me)
        cin>>letter;
        cout<<"'"<<letter<<"'"<<" has a frequency of "<<hashmap[letter]<<endl;
    }


    return 0;
}