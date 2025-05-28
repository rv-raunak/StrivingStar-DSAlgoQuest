/*
| **Operation**         | **Time Complexity** | **Explanation**                                                           |
| --------------------- | ------------------- | ------------------------------------------------------------------------- |
| **Push** (`push()`)   | O(1)                | Inserting an element at the back of the queue is done in constant time.   |
| **Pop** (`pop()`)     | O(1)                | Removing an element from the front of the queue is done in constant time. |
| **Front** (`front()`) | O(1)                | Accessing the front element of the queue is done in constant time.        |
| **Back** (`back()`)   | O(1)                | Accessing the back element of the queue is done in constant time.         |
| **Size** (`size()`)   | O(1)                | Returns the number of elements in the queue, which is stored internally.  |
| **Empty** (`empty()`) | O(1)                | Checks if the queue is empty, which is a constant time operation.         |
| **Clear** (`clear()`) | O(n)                | Removes all elements from the queue, requiring traversal of all elements. |



Detailed Explanation:
Push (push()):
The push operation inserts an element at the back of the queue. This is typically done in O(1) time, as it simply involves adding an element to the end of the queue.

Pop (pop()):
The pop operation removes the element from the front of the queue. Like push, this operation is done in O(1) time since it only involves removing the front element.

Front (front()):
The front operation accesses the front element without removing it. This is an O(1) operation since you are only retrieving the element at the front of the queue.

Back (back()):
The back operation accesses the back element without removing it. This is also O(1) because it involves just accessing the back of the queue.

Size (size()):
The size operation returns the number of elements in the queue. This is an O(1) operation since most queue implementations maintain a size counter internally.

Empty (empty()):
The empty operation checks whether the queue is empty. This is done in O(1) time, as it just checks if the size is 0.

Clear (clear()):
The clear operation removes all elements from the queue. This has O(n) time complexity because it involves traversing and deleting each element individually.

Summary of Queue Operations Time Complexities
Operation	Time Complexity
Push	O(1)
Pop	O(1)
Front	O(1)
Back	O(1)
Size	O(1)
Empty	O(1)
Clear	O(n)

Visual Summary:
Push: O(1)

Pop: O(1)

Front: O(1)

Back: O(1)

Size: O(1)

Empty: O(1)

Clear: O(n) (since it involves removing all elements)

This cheat sheet summarizes the time complexities of common queue operations. As you can see, most operations like push, pop, and front/back access are very efficient and take constant time, while clear involves linear time complexity due to removing all the elements from the queue.


*/




#include<iostream>
#include<queue>
using namespace std;


//queue is similar to stack but it follows the FIFO rule (First In First Out) //the guy who gets in first comes out first
//similar to stack here all the opertions are happening in constant time i.e. O(1);

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}



void explainQueue()
{
    queue<int> q;
    q.push(1);   //{1}
    q.push(2);   //{1,2}
    q.emplace(4);   //{1,2,4}

    printQueue(q);
    
    q.back() += 5; //as it returns the last value so it can be stored, printed or modified
    printQueue(q);
    cout<<q.back()<<endl;    //prints 9 

    // Q is {1,2,9}
    cout<<q.front()<<endl;  //prints 1
    printQueue(q);

    q.pop();  //{2,9}//pops the first element //doesn't return anything 
    printQueue(q);
    cout<<q.front()<<endl;   //prints 2

    //size swap empty same as stack


    //inserting multiple elements
    deque<int> dq = {0,-1,-2};
    queue<int, deque<int>> q2(dq);  //we can also use list here as underlying container

    printQueue(q2);

}

int main()
{
    explainQueue();
    return 0;
}


/*
### **Summary of `queue` in C++**  

1️⃣ **`queue` is an adapter container**, meaning it does not store elements directly but relies on an **underlying container** (`deque` by default). It follows the **FIFO (First In, First Out)** principle, where elements are inserted at the back and removed from the front.  

2️⃣ **No Indexing & No Iterators** → Unlike `vector` and `deque`, a `queue` does **not allow direct element access (`[]`, `.at()`) or iterators** because it is designed for sequential processing. You can only access the **front** (`front()`) and the **back** (`back()`).  

3️⃣ **Allowed Operations:**  
   - `push()` → Inserts an element at the **back**.  
   - `pop()` → Removes the **front** element.  
   - `front()` → Returns the **first** element.  
   - `back()` → Returns the **last** element.  

4️⃣ **Underlying Containers:**  
   - **`deque<T>`** → ✅ Default (fast push/pop from both ends).  
   - **`list<T>`** → ✅ Can be used for efficient insertions/deletions.  
   - **`vector<T>`** → ❌ Not allowed (inefficient front operations).  

5️⃣ **Comparison with `stack`**  
   - **`queue` → FIFO (First In, First Out)**, elements are removed from the front.  
   - **`stack` → LIFO (Last In, First Out)**, elements are removed from the top.  
   - Both **do not allow indexing or iterators** and work only with sequential access.  

### **🚀 Key Takeaways**  
✅ `queue` is used when elements must be processed in the order they arrive (e.g., task scheduling).  
❌ No indexing or random access like `vector` or `deque`.  
✅ Supports `push()`, `pop()`, `front()`, and `back()` for controlled access.  

Would you like a summary for `priority_queue` as well? 😃🚀



*/