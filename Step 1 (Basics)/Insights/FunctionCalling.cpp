#include<iostream>
using namespace std;

int passvalue()
{
    cout<<"Hello";
    return 6;
}

int main()
{
    int v; 
    v=passvalue(); //although we are assigning it to a variable but it also calls the function
    v=v+1;
    cout<<v;

    return 0;
}