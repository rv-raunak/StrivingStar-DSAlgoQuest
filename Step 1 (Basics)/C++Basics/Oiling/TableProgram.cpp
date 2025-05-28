#include<iostream>
using namespace std;

int main()
{
while(true)
{
    char choice;
    int table, range;

    cout << "Enter the Number for printing its table: ";
    cin>>table;

    cout<<"Enter the range of the table: ";
    cin>>range;

    for(int i = 1; i<=range; i++)
    {
        int result;
        result=table*i;
        cout<<table<<" X "<<i<<" = "<<result<<endl;
    }
    
    cout<<"Do you want to continue(y/n): ";
    cin>>choice;
    if(choice == 'n') 
    {
        cout<<"Program Terminated"; 
        break;
    }
}

    return 0;
}