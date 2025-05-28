#include<bits/stdc++.h>
using namespace std;

void explainUnorderedSet()
{
    //everything is same as set  i.e. all the oeprations are same be it insert, erase etc. except lower and upper bound functions do not work

    //however, the only difference is that it doesn't store in a sorted order

    //we don't know how it will store since it has a randamized order for storage (it can have any order)

    //this means that it is unique but not sorted

    //in most of the cases

    //lower_bound and upper_bound function doesn't work, but rest all the functions are same

    //as above, it does not store in any particular order so it has a better complexity than set in most cases, except some when collision happens


    //in most of the cases the Time Complexity is O(1) constant time but here's a catch in the worst case (which happens once in a millennium) i.e. the data is possibly grouped in such a way that they want us to explore the worst case then the Unordered Set takes O(n) Linear Time Complexity (bu this happens only once in a blue moon)

    //we'll understand these things when we would grow in experience
}

int main()
{
    explainUnorderedSet();
    return 0;
}


/*
Here’s a comprehensive Time Complexity Cheat Sheet for C++ std::unordered_set, which is implemented using a hash table.

✅ Unordered Set Time Complexity Cheat Sheet
| **Operation**       | **Average Case** | **Worst Case** | **Explanation**                                                          |
| ------------------- | ---------------- | -------------- | ------------------------------------------------------------------------ |
| `insert(val)`       | O(1)             | O(n)           | Inserts a value. If hash collisions occur, worst-case time increases.    |
| `erase(val)`        | O(1)             | O(n)           | Removes the element with the given key (if exists).                      |
| `erase(iterator)`   | O(1)             | O(1)           | Deletes the element at the iterator.                                     |
| `find(val)`         | O(1)             | O(n)           | Returns iterator to the element if found.                                |
| `count(val)`        | O(1)             | O(n)           | Returns 1 if the element exists, 0 otherwise.                            |
| `size()`            | O(1)             | O(1)           | Returns number of elements.                                              |
| `empty()`           | O(1)             | O(1)           | Checks whether the set is empty.                                         |
| `clear()`           | O(n)             | O(n)           | Deletes all elements.                                                    |
| `begin()` / `end()` | O(1)             | O(1)           | Returns iterator to start or end.                                        |
| `bucket_count()`    | O(1)             | O(1)           | Returns total number of buckets used internally.                         |
| `load_factor()`     | O(1)             | O(1)           | Returns average number of elements per bucket.                           |
| `rehash(n)`         | O(n)             | O(n)           | Resizes hash table to have at least `n` buckets. May affect performance. |

🧾 Visual Summary:
| Operation    | Avg Case | Worst Case |
| ------------ | -------- | ---------- |
| Insert       | O(1)     | O(n)       |
| Erase (key)  | O(1)     | O(n)       |
| Find         | O(1)     | O(n)       |
| Count        | O(1)     | O(n)       |
| Size / Empty | O(1)     | O(1)       |
| Clear        | O(n)     | O(n)       |


*/