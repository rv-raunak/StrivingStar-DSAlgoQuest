/*
Visual Summary
Insertions/Deletions at Front/Back: O(1)

Insertions/Deletions in the Middle: O(n)

Accessing by Index: O(1)

Size/Empty: O(1)

Clear: O(n)

Resize: O(n)

Swap: O(1)

*/


//Dequeue means Double-Ended Queue
#include<iostream>
#include<deque>
using namespace std;

//Dequeue is same as list and vector
void print(deque<int> &x)  
{
    for(auto i: x)
    {
        cout<<i<<" ";
    }
}

void explainList()
{
    deque<int> dq; //empty list
    
    dq.push_back(2);  //{2}
    dq.emplace_back(4); //{2,4}
    
    dq.emplace_front(1); //{1,2,4}
    dq.push_front(5); //{5,1,2,4}  

    print(dq);

    cout<<endl<<dq.back()<<endl;  //access the last element (takes no argument)
    cout<<dq.front()<<endl;
    //access the first element (takes no argument)
}
int main()
{
    explainList();
    return 0;
}
/*

Key Differences Between deque and list

| Feature                         | **`deque` (Double-ended queue)**                                                     | **`list` (Doubly Linked List)**                                                                    |
| ------------------------------- | ------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------- |
| **Underlying Structure**        | **Dynamic Array** with two ends, using a block of memory divided into chunks.        | **Doubly Linked List** with nodes containing data and pointers to both previous and next elements. |
| **Access Time**                 | **O(1)** for both front and back (constant time).                                    | **O(1)** for both front and back (constant time).                                                  |
| **Insert/Remove at Front**      | **O(1)** for front. No shifting required at either end.                              | **O(1)** for front, but may require pointer manipulation.                                          |
| **Insert/Remove at Back**       | **O(1)** for back (constant time).                                                   | **O(1)** for back, but involves pointer updates.                                                   |
| **Insert/Remove in the Middle** | **O(n)** for the middle (like `vector`).                                             | **O(1)** at any position (if the iterator is given).                                               |
| **Memory Structure**            | Allocates **multiple blocks of memory**; may require extra space due to chunks.      | Allocates memory for each element independently, requiring space for **two pointers** per element. |
| **Space Complexity**            | **O(n)** (like `list`), but with possible overhead due to chunked memory allocation. | **O(n)**, with additional memory usage for the pointers.                                           |
-------------------------------------------------------------------------------------------------------------------------------------------

How deque Works:
deque is essentially a dynamic array that supports fast insertions and deletions at both ends (front and back).

It works by allocating multiple blocks of memory, and these blocks are linked together in such a way that the front and back of the container can grow independently.

Think of it as a list of arrays rather than just a single array.

Because it uses multiple chunks, insertions and deletions at both ends (front and back) are done in constant time, O(1).

How list Works:
list is a doubly linked list, meaning each element (node) has two pointers: one to the next node and one to the previous node.

Inserting or deleting at the front or back is done by adjusting the pointers of adjacent nodes, so these operations also take constant time (O(1)).

However, for insertions or deletions in the middle, you need to traverse the list from the front or back to reach the correct node, which takes O(n) time.

Which to Use?
Use deque when:

You need fast insertions and deletions at both the front and back, but also need the efficiency of a contiguous memory structure for random access.

You may also need fast access to elements by index (random access), as deque allows O(1) access, unlike list.

Use list when:

You do not need random access (i.e., you don’t need to access elements by index).

You need efficient insertions and deletions at both ends and possibly in the middle, especially if you have a large number of elements and don’t care about indexing.

Space Complexity Comparison:
deque uses multiple chunks of memory instead of a single contiguous block like vector. While each chunk is an array, it can result in extra overhead due to the way memory is allocated.

list uses memory for each individual node, which requires extra space for the two pointers (next and previous) in addition to the element’s data.

Space Overhead:
deque has some overhead due to its chunking structure, but random access is possible, and it uses space more efficiently than a list in terms of memory fragmentation.

list has overhead for storing two pointers per node, making it more memory-consuming than deque in terms of per-element space.





*/




















/*
| **Operation**                     | **Time Complexity** | **Explanation**                                                                       |
| --------------------------------- | ------------------- | ------------------------------------------------------------------------------------- |
| **Accessing by index**            | O(1)                | Random access is allowed, so accessing an element by index is constant time.          |
| **Push Front** (`push_front()`)   | O(1)                | Insertion at the front of the deque is done in constant time.                         |
| **Push Back** (`push_back()`)     | O(1)                | Insertion at the back of the deque is done in constant time.                          |
| **Pop Front** (`pop_front()`)     | O(1)                | Deletion from the front of the deque is done in constant time.                        |
| **Pop Back** (`pop_back()`)       | O(1)                | Deletion from the back of the deque is done in constant time.                         |
| **Insert at middle** (`insert()`) | O(n)                | Inserting at an arbitrary position (not front/back) may require shifting elements.    |
| **Erase at middle** (`erase()`)   | O(n)                | Erasing an element from the middle may require shifting elements.                     |
| **Size** (`size()`)               | O(1)                | Returns the number of elements, which is stored internally.                           |
| **Empty** (`empty()`)             | O(1)                | Checks if the deque is empty, which is a constant time operation.                     |
| **Clear** (`clear()`)             | O(n)                | Removes all elements from the deque, requiring traversal of all elements.             |
| **Front** (`front()`)             | O(1)                | Accessing the front element of the deque is done in constant time.                    |
| **Back** (`back()`)               | O(1)                | Accessing the back element of the deque is done in constant time.                     |
| **Resize** (`resize()`)           | O(n)                | Resizing the deque may involve allocating and copying elements to a new memory block. |
| **Swap** (`swap()`)               | O(1)                | Swaps the contents of two deques in constant time (assuming no memory reallocation).  |




-------------------------------------------------------------------------------------------------------------------------------------------
Detailed Explanation:
Accessing by Index:
Just like a vector, you can access elements at any index in constant time, O(1), because deque supports random access (though not contiguous memory like vector).

Push and Pop Operations (Front and Back):
Both push_front(), push_back(), pop_front(), and pop_back() are efficient because deque maintains pointers to both the front and the back, so these operations are done in constant time (O(1)).

Insert and Erase at Middle:
While insertions and deletions at the front or back are efficient, doing them in the middle involves shifting elements, which can take O(n) time in the worst case.

Size and Empty:
Both size() and empty() are constant time operations because deque internally keeps track of the number of elements.

Clear:
clear() removes all elements, and in the worst case, you need to traverse and delete each element, leading to O(n) complexity.

Resize:
Resizing a deque can take O(n) time because, unlike a vector, resizing a deque may involve allocating new memory and copying the existing elements to the new memory blocks.

Swap:
Swapping two deques is a constant time operation because it involves swapping the internal pointers, rather than copying or moving the elements themselves.|

*/