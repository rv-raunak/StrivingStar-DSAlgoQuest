#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];  //choosing the first element as the pivot element 
    
    // initialization
    int i = low;  
    int j = high; 
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }

        while(arr[j]>pivot && j>=low+1)
        {
            j--;
        }

        if(i<j) swap(arr[i], arr[j]);
        
    }
    
    swap(arr[low], arr[j]); //don't write pivot here as its just the copy  and not the actual value
    return j;
}

void quicksort(vector<int> &arr,  int low, int high)
{
    if(low<high)
    {
        int partition = f(arr, low, high);
        quicksort(arr, low, partition-1);  //for sorting th eleft half
        quicksort(arr, partition+1, high);  //for sorting the right half
    }

}

int main()
{
    vector<int>v;
    cout<<"Enter as many elements you want just add '-' at end if you wanna stop the vector"<<endl;
    cout<<"Enter Elements: ";
    int element;
    while(element!=-1)
    {
        cin>>element;
        v.push_back(element);
    }
    
    //alternate logic for it
    //you can also print the array to its actual length using this logic 
    //and even put correct parameter in the quicksort
    // while(cin>>element && element!=-1)
    // {
    //     v.push_back(element); 
    // }
    
    
    //vector before sorting
    for(int x: v) 
    {
        if(x==(v[v.size()-1])) break;
        cout<<x<<" ";
    }
    
    quicksort(v, 0, v.size()-2);
    cout<<endl;
    //vector after sorting
    for(int x: v) 
    {
        if(x==(v[v.size()-1])) break;
        cout<<x<<" ";
    }
            return 0;
}


/*
Doubt clarification

why does pivot give wrong answer and arr[low] give different naswer when I have declared they are the same in f()


ChatGPT said:
Great question, Vaibhav — and it touches on a very important concept in C++: the difference between a value and a reference.

🤔 Let's look at this line in your function:
cpp
Copy
Edit
int pivot = arr[low];
Here, you are copying the value at arr[low] into a new variable called pivot. So now:

pivot is a separate variable, stored at a different memory location.

Even though it has the same value initially as arr[low], any changes to pivot will NOT affect arr[low], and vice versa.

🧨 The mistake:
Later, you tried this:

cpp
Copy
Edit
swap(pivot, arr[j]);
You meant to move the pivot into its correct place in the array. But you’re swapping a copy (pivot) with arr[j], which has no impact on arr[low] (the actual pivot in the array). So the array remains incorrect.

✅ The correct approach:
Instead of using a separate pivot variable, you should work with the array directly:

cpp
Copy
Edit
int pivot = arr[low];  // ok to store value
...
swap(arr[low], arr[j]);  // move actual pivot to its correct position
This swaps the original pivot in the array to its correct location (j), ensuring the array is correctly partitioned.

⚠️ Quick analogy:
Imagine arr[low] = ₹50 and you do int pivot = arr[low];. Now:

arr[low] is a ₹50 note.

pivot is a photocopy of that ₹50 note.

Swapping the photocopy with another real note doesn’t change the notes in your wallet.

You need to move the real ₹50 note (i.e., arr[low]) to a new position, not a photocopy.

*/