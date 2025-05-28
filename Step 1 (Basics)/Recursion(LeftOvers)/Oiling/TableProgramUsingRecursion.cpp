#include<iostream>
using namespace std;

//I have used backtracking here
void table(int num, int range)
    {
        if(range<1) return;
        table(num, range-1);
        cout<<num<<" X "<<range<<" = "<<num*range<<endl;
    }

int main()
{
    int num,range;
    cout<<"Enter Number: ";
    cin>>num;

    cout<<"Enter Range: ";
    cin>>range;

    table(num, range);
    return 0;
}

/*
#include<iostream>
using namespace std;


void table(int num, int range, int i = 1)
    {
        if(i>range) return;
        cout<<num<<" X "<<i<<" = "<<num*i<<endl;
        table(num, range, i+1);
    }

int main()
{
    int num,range;
    cout<<"Enter Number: ";
    cin>>num;

    cout<<"Enter Range: ";
    cin>>range;

    table(num, range);
    return 0;
}


*/

//------------------------------------------------------------------------------//




/*
#include<iostream>
using namespace std;

int i = 1;
void table(int num, int range)
    {
        if(i>range) return;
        cout<<num<<" X "<<i<<" = "<<num*i<<endl;
        i++;
        table(num, range);
    }

int main()
{
    int num,range;
    cout<<"Enter Number: ";
    cin>>num;

    cout<<"Enter Range: ";
    cin>>range;

    table(num, range);
    return 0;
}









*/