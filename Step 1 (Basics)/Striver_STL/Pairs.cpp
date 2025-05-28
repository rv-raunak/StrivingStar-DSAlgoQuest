#include<iostream>
#include<utility> //not necessary as <iostream> might already cover it //which here it actually does
using namespace std;

void ExplainPair()
{
    pair<int, int> p ={1,2};   //different datatypes can also be stored together
    cout<<p.first<<" "<<p.second<<endl;



    //Nested Pair
    //nested pair property to store and access more values
    pair<int, pair<int, int>> p1= {1, {3, 4}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
    //cout<<p1.second cannot be printed as cout doesn't know how to handle pair directly

    //re-declaration of the same variable is not possible;



    //making an array containing pairs
    pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};
    cout<<arr[1].first<<endl;
    cout<<arr[1].second<<endl; 
    //this proves that pairs can also be treated as a datatype in C++

}

int main()
{
    ExplainPair();
    return 0;
}