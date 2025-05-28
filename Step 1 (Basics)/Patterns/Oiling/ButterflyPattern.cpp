#include<bits/stdc++.h>
using namespace std;

void Butterfly(int n)
{
    //upper wings
    for(int i = 1; i<=n; i++)
    {
        if(i==n)
        {
            for(int j=1; j<=2*n-1; j++)
            {
                cout<<"*";
            }
            cout<<"\n";
            break;
        }
        for(int j = 1; j<=i; j++)
        {
            cout<<"*";
        }

        for(int j = 1; j<=2*(n-i)-1; j++)
        {
            cout<<" ";
        }

        for(int j = 1; j<=i; j++)
        {
            cout<<"*";
        }    
        cout<<"\n";
    }
    
    //lower wings
    
    for(int i = 1; i<=n-1; i++)
    {
        for(int j = 1; j<=n-i; j++)
        {
            cout<<"*";
        }

        for(int j = 1; j<=2*(i)-1; j++)
        {
            cout<<" ";
        }

        for(int j = 1; j<=n-i; j++)
        {
            cout<<"*";
        }    
        cout<<"\n";
    }
    

}

int main()
{
    while(true)
    {
        int size;
        char choice;
        cout<<"Enter the size: ";
        cin>>size;
    
        Butterfly(size);
    
        cout<<"Do you want to continue this program (y/n)?: ";
        cin>>choice;

        if(choice=='n') break;
    }
    return 0;
}