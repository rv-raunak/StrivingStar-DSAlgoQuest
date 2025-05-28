
/*
| Operation                        | Time Complexity | Notes                                                               |
| -------------------------------- | --------------- | ------------------------------------------------------------------- |
| `list.push_front(x)`             | ✅ O(1)          | Adds element `x` at the front (beginning)                           |
| `list.push_back(x)`              | ✅ O(1)          | Adds element `x` at the back (end)                                  |
| `list.pop_front()`               | ✅ O(1)          | Removes the front element                                           |
| `list.pop_back()`                | ✅ O(1)          | Removes the last element                                            |
| `list.insert(pos, x)`            | ✅ O(1) at `pos` | Inserts `x` at the given position `pos` (assuming `pos` is known)   |
| `list.erase(pos)`                | ✅ O(1) at `pos` | Removes the element at the given position `pos`                     |
| `list.clear()`                   | ✅ O(n)          | Removes all elements                                                |
| `list.size()`                    | ✅ O(1)          | Returns the number of elements in the list                          |
| `list.empty()`                   | ✅ O(1)          | Checks if the list is empty                                         |
| `list.begin()`                   | ✅ O(1)          | Returns an iterator to the first element of the list                |
| `list.end()`                     | ✅ O(1)          | Returns an iterator to the past-the-end element                     |
| `list.front()`                   | ✅ O(1)          | Accesses the first element                                          |
| `list.back()`                    | ✅ O(1)          | Accesses the last element                                           |
| `list.find(x)`                   | ❌ O(n)          | Searches for element `x` (linear search)                            |
| `list.sort()`                    | ✅ O(n log n)    | Sorts the list using quicksort or other efficient sorting algorithm |
| `list.reverse()`                 | ✅ O(n)          | Reverses the list                                                   |
| `list.splice(pos, another_list)` | ✅ O(1)          | Transfers elements from `another_list` to `pos`                     |
| `list.merge(another_list)`       | ✅ O(n + m)      | Merges two sorted lists (O(n + m) for lists of sizes n and m)       |


📌 Important Notes:
Insertion and Deletion: Since list is a doubly linked list, inserting or deleting elements at any position is efficient (O(1)) if you already have an iterator pointing to that position.

Search Operations: Searching for elements like with find() takes O(n) because you need to traverse the entire list.

Sorting: The sort() function uses an efficient algorithm (O(n log n)), but keep in mind it still takes longer compared to a vector (due to pointer overhead).

-------------------------------------------------------------------------------------------------------------------------------------------


Detailed Space Comparison: vector vs list
Container	Space Complexity	Reason
vector	O(n)	Contiguous block of memory for elements. Extra space may be used due to capacity allocation.
list	O(n)	Each element is stored in a node with two pointers (next and previous), using more space per element.

Example of Space Usage:
vector<int>:
Suppose you have a vector<int> with 1 million elements. The total space required will be proportional to 1 million * size of int. Typically, int is 4 bytes, so the vector will take 4 million bytes (plus a bit more for capacity management).

list<int>:
For a list<int>, each node stores not just the integer but also two pointers (each usually 8 bytes on a 64-bit system). So, the space complexity for each element will be approximately 4 bytes (int) + 2 * 8 bytes (pointers) = 20 bytes per element.

For 1 million elements, this results in 20 million bytes, which is 5 times larger than the vector in terms of space usage.



*/

#include<iostream>
#include<list>
using namespace std;

//List is exactly same as vector
//The only difference is that list gives you front operations as well
//Its also dynamic in nature just as vector

void print(list<int> &x)  //it modifies the same list which is much less costly than list<int> x (expensive copying operations)
{
    for(auto i: x)
    {
        cout<<i<<" ";
    }
}

void explainList()
{
    list<int> ls; //empty list
    
    ls.push_back(2);  //{2}
    ls.emplace_back(4); //{2,4}
    
    ls.emplace_front(1); //{1,2,4}  
    ls.push_front(5); //{5,1,2,4}  

    //directly pushes the element in the front
    //we can do the same using insert in vectors however, insert operation is much costly (as it takes a lot of time) than these front passing operations
    
    //this is because for list internally a double linked list is maintained unlike vector which maintains a singly linked list and therefore front operations gets much cheaper (as front part is much easier to access in doubly linked list)

    //❌ Correction: A vector does not maintain a singly linked list; rather, it maintains a contiguous dynamic array. (check it again once)

    //rest funcs are same as vectors
    //begin, end, rbegin, rend, clear, insert, size, swap
    
    print(ls);

}


int main()
{

    explainList();
    return 0;
}