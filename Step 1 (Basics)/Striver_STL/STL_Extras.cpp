#include<bits/stdc++.h>
using namespace std;

//these are some more extra algorithms along with the previous sorting ones which are generically used in your DS_Algo journey in day-to-day life

//Now many more algorithms are there but they are not widely used and you'll not be requiring them

//Whatever STL that has been taught in the video is actually more than enough to get started with C++



void explainExtras()
{
   //There is one more STL which is very important which is builtin_popcount()

   int num = 7; //Binary Form: 111 but since its int(32 bits) thus in actuality it is 0..........000000111 (32 bit number) 

   int cnt = __builtin_popcount(7); //so it basically gives the count of set bits or 1s in Binary form of the digits
   cout<<"No. of Set Bits: "<<cnt<<endl;  
//Important: This is a GCC/Clang builtin. For other compilers, you might need to use std::popcount() (C++20) or implement manually, but the hardware-supported versions are always O(1).
// So yes, it's constant time regardless of the input value!


   //for long long the syntax changes a bit
   long long num2 = 26572347807;
   cnt = __builtin_popcountll(num2);
   cout<<"No. of Set Bits: "<<cnt<<endl<<endl;
   
}
//    🔍 Notes:
// __builtin_popcount(int x) → For 32-bit integers.
// __builtin_popcountll(long long x) → For 64-bit integers.





void printPermutations(string s)
{
    //------------Next Thing: Finding Permutation possibilities
    //suppose for this string "123", I want to have all the permutation cases then I would make use of the next_permutation(start, end+1) function 
    
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));  
    //s.end() already points at one element after the last element so its already (End position + 1)

    //remember that this prints all the permutations of string as per dictionary order

    //And here the same string s is being modified again and again (no extra copies are created)

    //here in the line -> while(next_permutation(s.begin(), s.end())); ->this returns true for every permutation of s until it reaches null (when no more permutation is left).  And when null occurs then this while loop becomes false and it stops.
    //Thus, when there is no more permutation i.e. null value then it returns false and then the while loop breaks
    
}


void explainNextPermutation()
{

    //Remember: Since it prints in the dictionary order i.e. ascending so we have to give the string in sorted order already in order to find all the permutations, otherwise it will miss many permutation before it.

    //Before using nxt_permutation function, we must first sort the string before passing it as the parameter of the next_permutation function
    cout<<"Case: 1 (Already Sorted Case)"<<endl;
    printPermutations("123");
    cout<<endl;
    
    cout<<"Case: 2 (Unsorted Case)"<<endl;
    printPermutations("132");
    cout<<endl;
    
    cout<<"Case: 3 (Sorting Case)"<<endl;
    string s="CBA";
    sort(s.begin(), s.end());
    cout<<"Sorted Instance: "<<s<<endl;
    printPermutations(s);
    cout<<endl;
    
    cout<<"Case: 4 (Unsorted Case)"<<endl;
    string s1="BCA";
    cout<<"Unsorted Instance: "<<s1<<endl;
    printPermutations(s1);
    cout<<endl;

    /*
TIME COMPLEXITY OF next_permutation(): O(n! × n)

SINGLE CALL: O(n)
- Has to scan and rearrange parts of the string/array
- Each call does O(n) work to find the next permutation

GENERATING ALL PERMUTATIONS: O(n! × n)
- Total permutations = n! 
- Each permutation takes O(n) time to compute
- Total = n! × O(n) = O(n! × n)

EXAMPLE: string "abc" (n=3)
- 3! = 6 permutations exist
- Each next_permutation() takes O(3) time  
- Total time = 6 × O(3) = O(3! × 3)

KEY POINT: 
n! = how many permutations exist (math)
O(n! × n) = time to actually generate them all (programming)
*/
}


void MinMax()
{
    //Imagine you have an array like: {1, 10, 5, 6, 9, 34}
    //And you want the maximum element 
    int arr[] = {1, 10, 5, 6, 9, 34};
    int maxi = *max_element(arr,arr+6);  //[start iterator,  end iterator)
    //btw remember that max_element(arr,arr+6); a->this actually gives you the address but dereferencing it using the '*' operator actually gives the value at that address
    cout<<maxi<<endl;

    //we can even do selective slicing for it
    maxi = *max_element(arr, arr+4); //search area reduced to {1,10,5,6}
    cout<<maxi<<endl;


    //same goes for min element;  //everything is same as above
    int mini = *min_element(arr,arr+6);
    cout<<mini<<endl; 

    /*
TIME COMPLEXITY: O(n)

max_element(arr, arr+6):     O(6) = O(n)
max_element(arr, arr+4):     O(4) = O(n) 
min_element(arr, arr+6):     O(6) = O(n)

WHY O(n)?
- Both functions must scan through ALL elements in the given range
- They compare each element to find the maximum/minimum
- No way to avoid checking every element (unsorted array)
- Linear scan from start to end iterator

EXAMPLE:
arr[] = {1, 10, 5, 6, 9, 34}
max_element(arr, arr+6) checks: 1→10→5→6→9→34 (6 comparisons)
max_element(arr, arr+4) checks: 1→10→5→6 (4 comparisons)

SPACE COMPLEXITY: O(1) - only stores the current max/min value
*/



/*
max() vs max_element() - WHEN TO USE WHICH:

max() FUNCTION:
- Purpose: Compare 2 values OR small known lists
- Returns: The actual VALUE
- Time Complexity: O(1) for 2 values, O(n) for initializer list

max_element() FUNCTION:
- Purpose: Find max in arrays/containers using iterators
- Returns: ITERATOR (address) - use * to get value
- Time Complexity: O(n)

INITIALIZER LIST: {1,2,3,4} - Direct list of values in curly braces

EXAMPLES:

// max() with 2 values - O(1)
int a = 5, b = 10;
int result = max(a, b);                    // Returns 10

// max() with initializer list - O(n) 
int result = max({1, 5, 3, 9, 2});         // Returns 9 (checks all 5 values)
int result = max({height, width, depth});   // Returns largest of 3 values

// max() in conditions - O(1)
if(max(x, y) > 100) { ... }

// max_element() with arrays - O(n)
int arr[] = {1, 5, 3, 9, 2};
int maxVal = *max_element(arr, arr+5);     // Returns 9

// max_element() with vectors - O(n)
vector<int> v = {1, 5, 3, 9, 2};
int maxVal = *max_element(v.begin(), v.end());  // Returns 9

// max_element() partial range - O(3)
int maxInSlice = *max_element(arr+1, arr+4);    // Checks {5,3,9}, returns 9

WHEN TO USE WHICH:
✓ max(): 2 values or small fixed lists you type directly
✓ max_element(): Arrays, vectors, any container with iterators

Same logic applies to min() vs min_element()
*/



}


    
    
    int main()
    {
        explainExtras();
        explainNextPermutation();
        MinMax();
        return 0;
    }