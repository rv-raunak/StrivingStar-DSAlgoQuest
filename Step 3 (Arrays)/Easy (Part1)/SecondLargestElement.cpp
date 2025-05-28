#include <bits/stdc++.h> // Avoid in real projects; use specific headers
using namespace std;
//note: this is my code I just refined it a bit using CHAT_GPT

// Brute-force method to find second largest element
int BruteForce_Approach(int arr[], int n)
{
    sort(arr, arr + n); // Sorts array in ascending order

    int max = arr[n - 1]; // Last element is maximum after sorting

    // Traverse from end to find first element less than max
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != max)
            return arr[i]; // This is the second largest
    }

    // All elements are same (no second largest)
    return INT_MIN;
    // Could return -1 or a custom message in real use case

    //Time Complexity: O(NlogN), For sorting the array
    //Space Complexity: O(1)
}





int Better_Approach(int arr[], int n)
{
    //here we'll have two passes, in pass we would check for the largest element and in the second pass we''' check for the second largest element(by filtering out the largest element which is not equal to the actuall largest that is actually found)

    //first pass: finding the largest element
    int max = arr[0];                           //assumption
    for(int i = 0; i<n; i++)
    {
        if(max<arr[i]) max=arr[i];
    }

    //second pass: finding the second largest element (not equal to max)
    int secmax = -1;    //can take INT_MIN if -ve elemeents are also ignored
    for(int i = 0; i<n;i++)
    {
        if(arr[i]>secmax && arr[i]!=max)     //can also be (arr[i]>secmax && arr[i]<max)
        {
            secmax=arr[i];
        }
    }

    return secmax;  //this is great as if no element is the secmax(i.e. all are same) then it will not enter the 'if' condition at any iteration and we will get the default value secmax i.e. -1 here

    
    //Time Complexity: O(2N) (to be precise)   //as we have two for-loops for rwo-passess
    //Space Complexity: O(1)


 }


 int Optimal_Approach(int arr[], int n)
 {
    int max = arr[0];
    int secmax= INT_MIN;
    
    for(int i = 0; i<n; i++)
    {
        if(arr[i]!=max && arr[i]>max)  //although its a safe short-circuit but doing arr[i]>max only does the job and arr[i]!=max is redundant here
        {
            secmax=max;   
            max=arr[i];
        }

        if(arr[i]<max && arr[i]>secmax)  //don't think that arr[i]<max is redundant like the first one, its actually imp to filter out equal to cases and duplicates of max would always be gretaer than secmax so must filter out them too thus this condition is both a general and important firebal
        {
            secmax=arr[i];
        }

        //Time Complexity: O(N), Single-pass solution
        //Space Complexity: O(1)
    }
    

    return secmax;
 }


int main()
{
    int n;
    cout << "Enter Array Size: ";
    cin >> n;

    if (n < 2)
    {
        cout << "Array should have at least two elements.\n";
        return 0;
    }

    int arr[n];
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int secmax = BruteForce_Approach(arr, n);

    if (secmax == INT_MIN)
        cout << "No second largest element exists (all elements are same).\n";
    else
        cout << "Second largest element by brute-force approach: " << secmax << endl;



    //this time I wrote it directly
    int secmax2 = Better_Approach(arr,n);
    cout<<"Second largest element by Better_approach is: "<<secmax2<<endl;
    
    
    
    int secmax3 = Optimal_Approach(arr,n);
    cout<<"Second largest element by Optimal_approach is: "<<secmax3<<endl;


    return 0;
}





/*
Chat_GPT's solution (although same as mine for (optimal solution) but with explainatory comments)
int Optimal_Approach(int arr[], int n)
{
    int max = arr[0];               // stores the maximum value
    int secmax = INT_MIN;          // stores second largest; initialized to INT_MIN to handle negative inputs

    for (int i = 1; i < n; i++)     // start from index 1 since arr[0] is already assumed as max
    {
        if (arr[i] > max)
        {
            secmax = max;          // old max becomes new second max
            max = arr[i];          // update max to current element
        }
        else if (arr[i] < max && arr[i] > secmax)
        {
            secmax = arr[i];       // valid candidate for second max
        }
        // if arr[i] == max, skip it (don't update secmax)
        // if arr[i] < secmax, ignore it too
    }

    return secmax;  // if no second max exists (all elements same), returns INT_MIN
}



*/