#include<iostream>
using namespace std;

void Diamond(int n)
{
    //upper triangle
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n-i; j++)
        {
            cout<<" ";
        }

        for(int j = 1; j<=2*i-1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
    //lower triangle
    
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i-1; j++)
        {
            cout<<" ";
        }

        for(int j = 1; j<=2*(n-i+1)-1; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    int size;
    cout<<"Enter size: ";
    cin>>size;

    Diamond(size);
    return 0;
}