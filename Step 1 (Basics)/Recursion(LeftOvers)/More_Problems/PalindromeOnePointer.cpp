//checking palindrome using recursion (functional code) but remember its case sensitive
#include<iostream>
using namespace std;

bool checkPalindrome(int i, string &s)    //here passing by reference doesn't much matter here you could have simply written string s
{
    if (i >= s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return checkPalindrome(i+1, s);
}

int main()
{
    string s;
    cout<<"Enter the String: ";
    cin>>s;

    cout<<checkPalindrome(0, s);
    return 0;
}