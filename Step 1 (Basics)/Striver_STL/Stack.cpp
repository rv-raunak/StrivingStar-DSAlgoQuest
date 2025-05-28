/*
| **Operation**         | **Time Complexity** | **Explanation**                                                           |
| --------------------- | ------------------- | ------------------------------------------------------------------------- |
| **Push** (`push()`)   | O(1)                | Pushing an element onto the stack is done in constant time.               |
| **Pop** (`pop()`)     | O(1)                | Popping an element from the stack is done in constant time.               |
| **Top** (`top()`)     | O(1)                | Accessing the top element of the stack is done in constant time.          |
| **Size** (`size()`)   | O(1)                | Returns the number of elements in the stack, which is stored internally.  |
| **Empty** (`empty()`) | O(1)                | Checks if the stack is empty, which is a constant time operation.         |
| **Clear** (`clear()`) | O(n)                | Removes all elements from the stack, requiring traversal of all elements. |



Detailed Explanation:
Push (push()):
The push operation inserts an element at the top of the stack. Since stacks are typically implemented using dynamic arrays or linked lists, this operation is done in O(1) time as it only involves adding the new element at the end of the stack (top).

Pop (pop()):
The pop operation removes the top element of the stack. Like push, this is also done in O(1) time because no elements need to be shifted; it’s just removing the top element.

Top (top()):
The top operation retrieves the top element without removing it. This operation is O(1) because it simply involves accessing the element at the top of the stack.

Size (size()):
The size operation returns the number of elements in the stack. This is an O(1) operation because stacks internally maintain a counter of the elements (in most implementations), so it doesn’t require traversing the stack.

Empty (empty()):
The empty operation checks if the stack is empty. Since the stack maintains a count of elements, checking if it's empty is done in O(1) time by simply checking if the size is 0.

Clear (clear()):
The clear operation removes all elements from the stack. It has O(n) complexity because, in most implementations, the elements are individually removed one by one, requiring traversal of the entire stack.

Summary of Stack Operations Time Complexities
Operation	Time Complexity
Push	O(1)
Pop	O(1)
Top	O(1)
Size	O(1)
Empty	O(1)
Clear	O(n)

Visual Summary:
Push: O(1)

Pop: O(1)

Top: O(1)

Size: O(1)

Empty: O(1)

Clear: O(n) (since it involves removing all elements)

This cheat sheet covers the time complexities for common stack operations. Since a stack is based on the LIFO (Last-In, First-Out) principle, most of the operations (like push, pop, and top) are constant time. The exception is clear, which takes linear time to remove all elements.


*/


#include<iostream>
#include<stack>
using namespace std;


//using stack 
//its an adapter container unlike list and vectors and can wrap around by using them as underlying containers
//no indexing is here
//so we can't iterate it directly using loops too
//only 3 operations are allowed here: push(), pop(), top() (+other commmon functions)
//all the operations take O(1) time. (constant time) (same is the case with queue)

//follows the LIFO principle (Last In First Out)

void printStack(stack<int> s) { // Pass by value to modify a copy (thus not affecting the original stack)
    while (!s.empty()) {
        cout << s.top() << " "; // Print top element
        s.pop(); // Remove top element
    }
    cout << endl;
}

void explainStack()
{
    stack<int> st;
    st.push(1);  //{1}
    st.push(2);  //{2,1}
    st.push(3);  //{3,2,1}
    st.push(3);  //{3,3,2,1}
    st.emplace(5);  //{5,3,3,2,1}  //top->bottom = left->right

    //we can create / declare multiple stacks simultaneously like a variables (same for all containers) ---> stack <int> st, st1, st2;   (this creates 3 different stacks at once)
    
    
    printStack(st);
    cout<<st.top()<<endl;   //returns the topmost element in the stack but that element still stays in the stack
 
    st.pop(); //this doesn't store or print the values //just deletes/pops out the current top element 
    cout<<st.top()<<endl;   //new top element within the stack
    cout<<st.size()<<endl; //4
    
    
    stack<int> st1, st11; //this means two empty stacks are created //no use as of now

    deque<int> dq = {1, 2, 3};
    stack<int, deque<int>> st2(dq);
    //if I didn't do this then I would have to enter or push the elements manually all by myself


    st.swap(st2);
    printStack(st); //here it stored the elements in LIFO manner quite cool right!!
    printStack(st2);
    //the stacks are swapped too

    cout<<st.empty();  //prints 0 or false as its not empty

}
int main()
{
    explainStack();
    return 0;
}



/*
### **Summary of Container Adapters and Underlying Containers**  

1️⃣ **Container Adapters (`stack`, `queue`, `priority_queue`)** allow **two template arguments**:  
   - **First argument** → Data type (`int`, `char`, etc.).  
   - **Second argument** → The **underlying container** used for storage (`deque`, `vector`, `list`).  

2️⃣ **Default Underlying Containers:**  
   - `stack<T>` → Uses **`deque<T>`** by default.  
   - `queue<T>` → Uses **`deque<T>`** by default.  
   - `priority_queue<T>` → Uses **`vector<T>`** by default.  

3️⃣ **Why Specify an Underlying Container?**  
   - `deque` allows **fast push/pop from both ends**, making it a good default for `stack` and `queue`.  
   - `vector` is better for **memory efficiency** in `priority_queue`.  
   - `list` can be used for **constant-time insertions** but uses more memory due to extra pointers.  

4️⃣ **Only Container Adapters Allow Two Arguments**  
   - ✅ `stack<int, deque<int>> st(dq);` → **Valid**  
   - ✅ `queue<int, list<int>> q(lst);` → **Valid**  
   - ❌ `vector<int, deque<int>> v;` → **Invalid** (normal containers do not use an adapter pattern).  

5️⃣ **`priority_queue` Special Case:**  
   - Has a **third argument** for custom sorting:  
     ```cpp
     priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
     ```
   - **First argument:** Data type (`int`).  
   - **Second argument:** Underlying container (`vector<int>` by default).  
   - **Third argument:** Comparator (`greater<int>` for min-heap).  

6️⃣ **Why Can't We Print a `stack` or `queue` Directly?**  
   - Unlike `vector`, `stack` and `queue` **do not support iterators** (they are designed for restricted access).  
   - To print a `stack`, we **pop** elements one by one while storing them in another container if needed.  

7️⃣ **Example Usage of Different Underlying Containers:**
   ```cpp
   stack<int, vector<int>> st(vec);  // Uses vector instead of deque
   queue<int, list<int>> q(lst);     // Uses list instead of deque
   priority_queue<int, deque<int>> pq(dq);  // Uses deque instead of vector
   ```

### **🚀 Key Takeaways**
- **Container adapters (`stack`, `queue`, `priority_queue`) allow specifying the underlying container.**  
- **Normal containers (`vector`, `list`, `deque`) do not allow this.**  
- `priority_queue` allows a **third argument** for custom sorting (like min-heap).  
- **Printing a `stack` or `queue` requires popping elements one by one.**  

Let me know if you need more clarification! 🚀😃




*/