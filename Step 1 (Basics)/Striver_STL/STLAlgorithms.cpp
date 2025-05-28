/*
From the above content we already covered Containers and Iterators
As of now Functions are not important so we can omit learning them
And thus, we'll be focusing now on the Algorithms(Most Used ones) and if there are algortims that might be left then we can learn them anyways at the moment when they are required while coding  afterwards
*/

#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1, pair<int,int> p2)
   {
    if(p1.second < p2.second) return true; //its like the comparator asking if the two pairs are in correct order or not for this condition and since its correct so we write true;

    if(p1.second > p2.second) return false; //same as above its again asking the same thing, but since we have written false so it understands that its not the correct order and it will internally swap the pairs to maintain the order

    //if both the above conditions are not met it means (p1.second == p2.second)  thus we don't need to write it explcitly 
    //thus the following code will flow if they are the same
    if(p1.first > p2.first) return true;
    return false; //else they are not sorted for second value being the same //so here it will internally swap the values

   }
   //thus for writing comparators always analyse everything in terms of two pairs and don't think in terms of arrays
   


void explainExtra()
{
    //In C++ STL we can just sort DS like arrays or vectors just by using sort() and we don't require to apply any of the sorting algorithms by ourselves like selection, insertion, merge sort etc.

    //syntax
    //sort(a, a + n)
        //here a = starting terator i.e. the pointing towards the first/starting position 9(usually)

        // And (a+n) is the ending iterator i.e. It should be always 1 after the desired element 

        //Ex: sort(a, a+4) //now it will start sorting from the element at index 0 to the element at index 3 (as the end guy is not included)


        //so actually this is [start,end) i.e. start is included and end is not included is derived from here and in extreme cases this extends up to :
        //sort(v.begin(), v.end()) [as end() always points after the last element, assuming you are using a vector]

    //so this way you can sort any containers like arrays and vectors etc. (but remember containers like map are excluded here)
    


    //we can also achieve selective sorting  (just like slicing)
    //Example: {3,1,7,5}
    //sort(a+2, a+4);
    //Output: {3,1,5,7} (Only Index 2 to index 3 will be sorted and rest will remain untouched)



    //Sorting in Descending Order
        //sort(a, a+n, greater<int>());
    //Thus sort(starting iterator,  ending iterator, greater<int>()) will sort the array in descending order within the desired range
    //here 'greator<int>()' is nothing but an in-built comparator which automatically sorts in the descending order




    //Implementation
    // Example 1: Sorting an array
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<sizeof(arr)<<endl; //gives the total number of bytes occupied by the whole array
    cout<<sizeof(arr[0])<<endl; //gives the number of bytes occupied by a single element
    cout<<n<<endl;  //there division gives the number of elements present

    //we took this appraoch to find length of array because .size() only works with containers like vector, string, etc., not with raw arrays

    // Sort entire array in ascending order
    sort(arr, arr + n);
    cout << "Sorted array (ascending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Example 2: Partial sorting (only index 2 to 3 i.e., a+2 to a+4)
    int arr2[] = {3, 1, 7, 5};
    sort(arr2 + 2, arr2 + 4); // Only sorts elements at index 2 and 3
    cout << "Partially sorted array: ";
    for (int i = 0; i < 4; i++) cout << arr2[i] << " ";
    cout << endl;

    // Example 3: Sorting in descending order
    int arr3[] = {4, 6, 1, 8, 2};
    sort(arr3, arr3 + 5, greater<int>());
    cout << "Sorted array (descending): ";
    for (int i = 0; i < 5; i++) cout << arr3[i] << " ";
    cout << endl;

    // Example 4: Sorting a vector
    vector<int> v = {10, 3, 7, 2};
    sort(v.begin(), v.end());  // ascending
    cout << "Sorted vector (ascending): ";
    for (int num : v) cout << num << " ";
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());  // descending
    cout << "Sorted vector (descending): ";
    for (int num : v) cout << num << " ";
    cout << endl;
    
/*
Doubt Clarification
why did you write arr name itself for the iterator in array?


ChatGPT said:
Great question, Vaibhav!

In C++, the name of the array (like arr) acts as a pointer to its first element. That’s why when we write:

cpp
Copy code
sort(arr, arr + n);

------------------------------------------------
It works perfectly — here's how:

arr points to the first element (i.e., &arr[0])

arr + n points to one position past the last element, which is the required end iterator (like in [start, end) syntax)
 
This behavior is specific to raw arrays, not to containers like vector. For vectors, we use:

cpp
Copy code
sort(v.begin(), v.end());
----------------------------------------------------
Because .begin() and .end() return iterators (which are like pointers) to the start and one-past-the-end of the vector.

Summary:
    arr = pointer to first element of array

    arr + n = one-past-the-last element

    This fits exactly with the sort(start, end) pattern

*/





//Creating Custom Comparators
//As of now we already know how to sort in increasing/decreasing order but we can also sort in our own custom way by defining our own custom comparator

//Example:
//let's declare a pair array
pair<int,int> a[]={{1,2}, {2,1}, {4,1}};

//What to do? Our task is to sort the given pair such that:
    //sort it according to second element 
    //if second element is same, then sort it according to the first element of a pair but in descending

//so let's write a self-written comparator which is essentially nothing but a boolean function
 //tips to write a custom comparator
    //->keep the same datatype as mentioned in the container in the parameter
    //->always take a couple or two guys as parameters and just write the logic for comparing the two elements thus orget about the container and just focus only on those two instances
    //after this the comparator will extend this logic to every element by taking two guys at a time for all the elements

   //Galti-Alert: I did the mistake of defining the comp here which is incorrect since comp is a boolean function and we can't define a function within a function so it has to be declared and defined separately(i.e. above here)

   sort(a, a+3, comp); 
   for(auto x: a)
   {
        cout<<'{'<<x.first<<" "<<x.second<<'}'<<" ";
   }
   cout<<'\n';
   //{{4,1}, {2,1}, {1,2}}


}

int main()
{
     explainExtra();
    return 0;
}