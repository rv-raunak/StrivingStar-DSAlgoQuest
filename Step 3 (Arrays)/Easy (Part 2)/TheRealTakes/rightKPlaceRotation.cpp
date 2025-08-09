#include<bits/stdc++.h>
using namespace std;

void rotateRight(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // finding the actual rotations 
        
        // ERROR 1: Variable Length Array (VLA) with Size 0
        // PROBLEM: int temp[k]; causes undefined behavior when k=0
        // WHEN: k % n == 0 (k is multiple of array length), k=0, or n=1
        // SOLUTION: Use vector instead (handles size 0 gracefully) OR add early return
        if (k == 0) return; // Early return prevents size 0 array
        vector<int> temp(k); // Use vector instead of VLA for safety
        
        // Store last k elements in reverse order
        int j = k-1;
        for(int i = n-1; i>=n-k; i--)
        {
            temp[j] = nums[i];
            j--;
        }

        // ERROR 2: Element Overwriting During Left-to-Right Shifting
        // PROBLEM: for(int i = 0; i < n-k; i++) nums[i+k] = nums[i];
        // WHAT HAPPENS: Elements get overwritten before they can be moved
        // SOLUTION: Shift right-to-left instead of left-to-right
        for(int i = n-k-1; i >= 0; i--) // Iterate backwards to avoid overwriting
        {
            nums[i+k] = nums[i]; // Each element moved exactly once
        }

        // Place stored elements at the beginning
        for(int i = 0; i<k; i++)
        {
            nums[i] = temp[i];
        }
    }

    int main()
    {
        int n; 
        cout<<"Enter Size: ";
        cin>>n;

        vector<int>arr;
        for(int i = 0; i<n; i++)
        {
            int element;
            cin>>element;
            arr.push_back(element);
        }


        int k;
        cout<<"Enter the number of rotations: ";
        cin>>k;

        rotateRight(arr, k);
        for(auto i: arr){cout<<i<<" ";}

        return 0;
    }