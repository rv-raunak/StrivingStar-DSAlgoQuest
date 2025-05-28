#include<iostream>
#include<set>
using namespace std;

//just need to remember 2 things for set:
    //->stores everything in a sorted order
    //->stores unique elements 
//In set, everything happens in logrithmic time complexity i.e. log(N) (Examples: Insertion and Deletion)


    //for stroing in the sorted fashion it maintains a tree (so its not a linear data structure) (We'll learn about the tree later)
void printset(set<int> x)
{
    for(set<int>::iterator it=x.begin(); it!=x.end(); it++)
    //auto it works here too
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void explainSet()
{
    set<int>st;  //empty set
    st.insert(1);  //{1}
    st.emplace(2); //{1,2}
    st.insert(2);  //{1,2}
    st.insert(4);  //{1,2,4}
    st.insert(3);  //{1,2,3,4}

    printset(st);
    //functionality of insert in vector
    // can be used also, that only increases
    //efficiency



    //begin(), end(), rbegin(), rend(), size()
    //empty() and swap() are the same as those of above 

    //functions
    //{1,2,3,4}
    auto it = st.find(3); //it actually returns an iterator that points to '3' in the set
    cout<<*(it)<<endl;
    //so since its an iterator, so it actually points at the address not at that value. We have to access that value indirectly.



    //{1,2,3,4}
    it = st.find(6); 
    //here we are trying to access the element that is not present in the set
    //here the it will always return st.end() as iterator which would just point after the last element (signifying that the element is outside the container)
    cout<<*(--it)<<endl;



    //{1,2,3,4}
    st.erase(3); //erases 3 but still maintains the sorted order  //takes logarithmic time
    printset(st);


    //a beautiful trick over here
    int cnt = st.count(3);
    cout<<cnt<<endl;
    //now this counts the frequency of an element in the set
    //but here's the catch // since set is unique and sorted so the count of any element can only be either 1 or 0.
    //And thus, this is more of an existence checker as if the element is present in the set then it will return 1 otherwise it will return 0


    //we can also erase using the iterator
    auto it2= st.find(4);
    st.erase(it); //it takes constant time
    printset(st);


    st.insert(4);  //{1,2,4}
    st.insert(3);  //{1,2,3,4}
    st.emplace(5); //{1,2,3,4,5}
    auto itr1 = st.find(2);
    auto itr2 = st.find(4);
    st.erase(itr1, itr2); //works on [start, end); or (begin(), end+1) principle 
    printset(st); //{1,4,5}


     //lower_bound() and upper_bound() function works in the same way as in vector it does 

     //other functions size(), empty(), swap(), begin() etc. are the same

     //find(), count(), insert() are the most important ones as functions in set

     //This is the syntax
     //refer the video to understand about these functions otherwise you'll learn it afterwards anyways
     auto itr3 = st.lower_bound(2);
     cout<<*itr3<<endl;
     itr3 = st.upper_bound(3);
     cout<<*itr3<<endl;
     printset(st);

}

int main()
{
    explainSet();
    return 0;
}


/*
| **Operation**       | **Time Complexity** | **Explanation**                                                          |
| ------------------- | ------------------- | ------------------------------------------------------------------------ |
| `insert()`          | O(log n)            | Inserts an element and maintains order.                                  |
| `erase(key)`        | O(log n)            | Deletes a specific key.                                                  |
| `erase(iterator)`   | O(1)                | Deletes the element at the given iterator.                               |
| `find(key)`         | O(log n)            | Searches for a specific key.                                             |
| `count(key)`        | O(log n)            | Returns 1 if key exists, 0 otherwise (since `set` stores unique values). |
| `lower_bound(key)`  | O(log n)            | Finds first element not less than key.                                   |
| `upper_bound(key)`  | O(log n)            | Finds first element greater than key.                                    |
| `equal_range(key)`  | O(log n)            | Returns a pair of iterators for the range of key (only one in `set`).    |
| `size()`            | O(1)                | Returns the number of elements.                                          |
| `empty()`           | O(1)                | Checks whether the set is empty.                                         |
| `clear()`           | O(n)                | Removes all elements.                                                    |
| `begin()` / `end()` | O(1)                | Return iterators to beginning/end.                                       |


🧠 Notes:
std::set stores elements in sorted order and maintains uniqueness.

Internally uses a Red-Black Tree, which is a type of self-balancing binary search tree.

All operations that involve searching or modifying a particular key take O(log n) time due to the tree structure.

Iterators are bidirectional.

🧾 Visual Summary:
Operation	Time Complexity
Insert	O(log n)
Erase (by key)	O(log n)
Erase (iterator)	O(1)
Find	O(log n)
Count	O(log n)
Lower Bound	O(log n)
Upper Bound	O(log n)
Equal Range	O(log n)
Size	O(1)
Empty	O(1)
Clear	O(n)

*/