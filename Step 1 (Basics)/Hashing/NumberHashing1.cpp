#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout<<"Enter Size Of The Array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter The Values: ";
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }



    //Pre-computing 
    int hash[13] = {0};    //This initiallizes all values to 0 in the array
    //Now as of now I have taken the size as 13 here since I know that the maximum element in my array is 12 (in this case)
    //Thus, while doing questions, I must see the max element and I should directly put max+1 as the size of the hash (so that I can get the index equal to the max element) 
    //Example: if the problem states that the size is 10^5 then I put hash[100001] simply
    //(besides, if in case I don't know max element then I can find it anyways and then do max+1)

    //The following code has a beautiful logic to make a hash array
    for(int i = 0; i<size; i++)
    {
        hash[arr[i]] += 1;
    }


    int q;
    cout<<"Enter The Number Of Times You Wanna Query The Array: ";
    cin>>q;
    // rememeber: by a query refers to asking that "how many times does this particular element appears in the array?"
    // and since you can ask this quesry for multiple elements so here we are taking the count of that


    cout<<"Enter Values You Wanna Query For: ";
    while(q--)
    {
        int number;
        cin>>number;
        //fetch (This can only happen when the hash array is created )
        cout<<number<<" has a frequency: "<<hash[number]<<endl;
    }

    return 0;
}
