#include<bits/stdc++.h>
using namespace std;

explainUnorderedmap()
{
    //same as set and unordered_set difference
    //so It will be unique but not sorted

    //it will store in a any randomized pattern
    //the difference is that map works in logrithmic of time i.e O(log(n))

    //but unordered_map in almost all cases works in constant time i.e. O(1) TC
    //however in worst case (which again happens once in a blue moon) it takes O(n) time complexity 

}

int main()
{
    return 0;
}
/*
Here’s a Time Complexity Cheat Sheet for C++ std::unordered_map, which is implemented using a hash table.

✅ Unordered Map Time Complexity Cheat Sheet
| **Operation**        | **Average Case** | **Worst Case** | **Explanation**                                                      |
| -------------------- | ---------------- | -------------- | -------------------------------------------------------------------- |
| `insert({key, val})` | O(1)             | O(n)           | Inserts a key-value pair. No duplicate keys allowed.                 |
| `erase(key)`         | O(1)             | O(n)           | Removes the element with the given key.                              |
| `erase(iterator)`    | O(1)             | O(1)           | Removes element at the given iterator.                               |
| `find(key)`          | O(1)             | O(n)           | Returns iterator to element with the given key if found.             |
| `operator[]`         | O(1)             | O(n)           | Accesses value by key; inserts a default value if key doesn't exist. |
| `at(key)`            | O(1)             | O(n)           | Returns reference to value; throws if key not found.                 |
| `count(key)`         | O(1)             | O(n)           | Returns 1 if key exists, else 0.                                     |
| `size()`             | O(1)             | O(1)           | Number of key-value pairs.                                           |
| `empty()`            | O(1)             | O(1)           | Checks if map is empty.                                              |
| `clear()`            | O(n)             | O(n)           | Removes all elements.                                                |
| `begin()` / `end()`  | O(1)             | O(1)           | Iterators to start and end (no order guaranteed).                    |
| `bucket_count()`     | O(1)             | O(1)           | Number of hash buckets.                                              |
| `load_factor()`      | O(1)             | O(1)           | Average number of elements per bucket.                               |
| `rehash(n)`          | O(n)             | O(n)           | Reorganizes into at least `n` buckets — may improve efficiency.      |



🧠 Key Notes:
unordered_map provides average O(1) time for access, insert, and delete.

It does not maintain any order of keys.

Collisions (many keys hashing to the same bucket) cause worst-case O(n).

Allows unique keys only.

Iterators are forward only (not bidirectional).




🧾 Visual Summary Table:
| **Operation**       | **Avg Case** | **Worst Case** |
| ------------------- | ------------ | -------------- |
| Insert              | O(1)         | O(n)           |
| Erase (by key)      | O(1)         | O(n)           |
| Access (`[]`, `at`) | O(1)         | O(n)           |
| Find / Count        | O(1)         | O(n)           |
| Erase (iterator)    | O(1)         | O(1)           |
| Size / Empty        | O(1)         | O(1)           |
| Clear               | O(n)         | O(n)           |

*/


/*
✅ Why unordered_map and unordered_set offer O(1) average time:
🔹 They use hash tables:
When you insert an element, its key is passed through a hash function.

This function returns a hash code (an integer), which determines the bucket index in an internal array.

So instead of searching sequentially or traversing a tree, the hash code jumps directly to the location (bucket) where the value/key should be.

🔹 That’s why lookup, insert, and delete are O(1) on average:
No traversal, no shifting — just hash, find the right bucket, and perform the operation.

⚠️ But why not guaranteed O(1)? Why O(n) in worst-case?
Because:

Hash Collisions:

Two different keys might have the same hash (called a collision).

In such cases, they’re stored in the same bucket (as a chain or list), making it take longer to search.

Too many elements → Load factor increases:

If the internal array becomes crowded, performance drops.

To handle this, the table resizes and rehashes all elements, which is expensive (but rare).



🧠 Summary
| Feature         | unordered\_map/set   | map/set                           |
| --------------- | -------------------- | --------------------------------- |
| Structure       | Hash Table           | Red-Black Tree (Balanced BST)     |
| Ordering        | No ordering          | Sorted by key                     |
| Lookup / Insert | O(1) avg, O(n) worst | O(log n) always                   |
| Use case        | Fast access by key   | Sorted iteration or range queries |

*/