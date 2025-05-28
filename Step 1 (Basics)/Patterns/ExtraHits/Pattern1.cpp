#include<iostream>
#include<vector>
using namespace std;

vector<int> storage(int n)
{ 
    int range = n*(n+1);
    vector<int> vec;
    for(int i = 1; i<=range; i++)
    {
        vec.push_back(i);
    }

    return vec;

}

bool searched(int search, vector<int> vec)
{
    for(int x: vec) 
    {
        if(search==x)
        return true;
    }

    return false;
}

int pattern(int n)
{
    vector<int> store = storage(n);
    vector<int> added, temp;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            if(i%2==0) 
            {
                    for(int value: store)
                    {
                        if(value%2==0 && !searched(value,added))
                        {
                            temp.push_back(value);
                            added.push_back(value);
                            break;
                        }
                    }
                    int mainvalue = temp[0];
                    temp.pop_back();
                    cout<<mainvalue<<" ";
                    //mainvalue=mainvalue+ 2; //not required
            }
            else
            {
                for(int value: store)
                    {
                        if(value%2!=0 && !searched(value,added))
                        {
                            temp.push_back(value);
                            added.push_back(value);
                            break;
                        }
                    }
                    int mainvalue = temp[0];
                    temp.pop_back();
                    cout<<mainvalue<<" ";
                    //mainvalue=mainvalue+ 2;  //not required

            }
        }
        cout<<endl;
    }
}

int main()
{
   int num;
   cout<<"Enter Number: ";
   cin>>num;
   pattern(num);

    return 0;
}