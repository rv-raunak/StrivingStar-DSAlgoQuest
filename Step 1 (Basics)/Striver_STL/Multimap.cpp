#include<bits/stdc++.h>
using namespace std;

explainMultimap()
{
    //similar to map, the only difference is that you can store duplicate keys here 
    //Example : {{1,2},{1,3}}  //this is valid now
    //Just as set and multiset
    
    //everything same as map, only it can store multiple keys
    //onlu mpp[key] cannot be used here

    //duplicate keys but still everything in the sorted order

}

int main()
{
    return 0;
}


/*
Here's a complete Time Complexity Cheat Sheet for C++ std::multimap, which is implemented as a self-balancing BST (usually Red-Black Tree) — just like map, but allows duplicate keys.

✅ Multimap Time Complexity Cheat Sheet
| **Operation**        | **Time Complexity** | **Explanation**                                                               |
| -------------------- | ------------------- | ----------------------------------------------------------------------------- |
| `insert({key, val})` | O(log n)            | Inserts a key-value pair. Duplicate keys are allowed.                         |
| `erase(key)`         | O(log n + k)        | Removes **all** elements with the specified key (k is the number of matches). |
| `erase(iterator)`    | O(1)                | Removes the element at the iterator.                                          |
| `find(key)`          | O(log n)            | Returns iterator to the **first occurrence** of the key.                      |
| `count(key)`         | O(log n + k)        | Returns the number of elements with the specified key.                        |
| `equal_range(key)`   | O(log n + k)        | Returns a pair of iterators (range) to all elements with given key.           |
| `lower_bound(key)`   | O(log n)            | First element with key **≥ given key**.                                       |
| `upper_bound(key)`   | O(log n)            | First element with key **> given key**.                                       |
| `size()`             | O(1)                | Number of key-value pairs.                                                    |
| `empty()`            | O(1)                | Checks whether multimap is empty.                                             |
| `clear()`            | O(n)                | Removes all elements.                                                         |
| `begin()` / `end()`  | O(1)                | Iterators to beginning and end (sorted by key).                               |


🧠 Key Points:
multimap stores elements in sorted order of keys (ascending by default).

Multiple values can have the same key.

Internally uses Red-Black Tree, like map.

You cannot use operator[] (unlike map) — because keys are not unique.

Iterators are bidirectional.


🧾 Summary Table:
| **Operation**       | **Time Complexity** |
| ------------------- | ------------------- |
| Insert              | O(log n)            |
| Erase (by key)      | O(log n + k)        |
| Erase (by iterator) | O(1)                |
| Find                | O(log n)            |
| Count               | O(log n + k)        |
| Equal Range         | O(log n + k)        |
| Lower / Upper Bound | O(log n)            |
| Size / Empty        | O(1)                |
| Clear               | O(n)                |



*/