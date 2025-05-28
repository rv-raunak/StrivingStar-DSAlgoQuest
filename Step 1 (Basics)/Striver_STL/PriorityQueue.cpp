#include<iostream>
#include<queue>
using namespace std;


//Time Complexities: //in both heaps
//push->log(n)
//pop->log(n)
//top-> O(1)




void printpq(priority_queue<int> pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}
//we have to define a separate printing func for minimum priority queue
void printpq(priority_queue<int, vector<int>, greater<int>>pq)
{
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

void explainPQ()
{
    //here remember that the data stored internally is not stored in a linear fashion and a tree data-structure is maintained

    //Maximum heap
    priority_queue<int>pq;
    pq.push(5);   //{5}
    pq.push(2);   //{5,2}
    pq.emplace(8);   //{8,5,2}
    pq.emplace(10); //{10,8,5,2}   //top->bottom = left->right

    printpq(pq);
    cout<<pq.top()<<endl; //10

    pq.pop();  //{8,5,2}
    printpq(pq);
    cout<<pq.top()<<endl;  //8

    //size swap empty function same as others

    //Minimum Heap
    priority_queue<int, vector<int>, greater<int>>mq;
    mq.push(5);   //{5}
    mq.push(2);   //{2,5}
    mq.emplace(8);   //{2,5,8}
    mq.emplace(10); //{2,5,8,10}
    printpq(mq);

    cout<<mq.top()<<endl;  //2
    mq.pop();  //{5,8,10}
    printpq(mq);

}


int main()
{
    explainPQ();
    return 0;
}


/*
| **Operation**         | **Time Complexity** | **Explanation**                                                                                             |
| --------------------- | ------------------- | ----------------------------------------------------------------------------------------------------------- |
| **Push** (`push()`)   | O(log n)            | Insertion of an element into the priority queue takes logarithmic time to maintain heap property.           |
| **Pop** (`pop()`)     | O(log n)            | Removing the top element (max or min depending on the priority) requires re-heapification, taking O(log n). |
| **Top** (`top()`)     | O(1)                | Accessing the top element is done in constant time, as it's always at the root of the heap.                 |
| **Size** (`size()`)   | O(1)                | Returns the number of elements in the priority queue, which is stored internally.                           |
| **Empty** (`empty()`) | O(1)                | Checks if the priority queue is empty, which is done in constant time.                                      |
| **Clear** (`clear()`) | O(n)                | Removing all elements from the priority queue requires iterating over all elements.                         |
| **Swap** (`swap()`)   | O(1)                | Swaps the contents of two priority queues in constant time (assuming no extra heap adjustments are needed). |


Detailed Explanation:
Push (push()):
The push operation inserts a new element into the priority queue. Since a priority queue is typically implemented using a heap (usually a binary heap), it needs to maintain the heap property after each insertion. The time complexity of this operation is O(log n) because the new element is inserted at the end, and the heap needs to be "re-heapified" by bubbling the element up the tree to its correct position.

Pop (pop()):
The pop operation removes the top element from the priority queue (which is the maximum element in a max-heap or the minimum in a min-heap). After removing the top element, the heap needs to maintain its heap property, so elements are re-arranged, requiring a logarithmic time operation. Thus, pop takes O(log n) time.

Top (top()):
The top operation returns the element at the top of the priority queue, which is always the root of the heap. This operation is O(1) because accessing the root element of the heap is instantaneous.

Size (size()):
The size operation returns the number of elements currently in the priority queue. This is an O(1) operation because the size is stored internally and doesn't require traversing the queue.

Empty (empty()):
The empty operation checks if the priority queue contains any elements. This is an O(1) operation because it simply checks if the size is 0.

Clear (clear()):
The clear operation removes all elements from the priority queue. Since it involves removing each element individually, the time complexity is O(n), where n is the number of elements in the priority queue.

Swap (swap()):
The swap operation swaps the contents of two priority queues. This operation is done in O(1) time because it involves swapping internal pointers or references to the heap structures, without re-ordering the elements themselves.

Summary of Priority Queue Operations Time Complexities
Operation	Time Complexity
Push	O(log n)
Pop	O(log n)
Top	O(1)
Size	O(1)
Empty	O(1)
Clear	O(n)
Swap	O(1)

Visual Summary:
Push: O(log n)

Pop: O(log n)

Top: O(1)

Size: O(1)

Empty: O(1)

Clear: O(n)

Swap: O(1)




*/