#include<bits/stdc++.h>
using namespace std;

void printMS(multiset<int> ms)
{
    for(multiset<int>::iterator i = ms.begin(); i!=ms.end(); i++)
    {
        cout<<*i<<" ";
    }

    cout<<'\n';
}



void explainMultiSet()
{
    //Everything is same as set
    //However, its stores duplicate elements also
    //Thus, its sorted but not unique this time


    multiset<int>ms;
    ms.insert(1); //{1}
    ms.insert(2); //{1,2}
    ms.insert(1); //{1,1,2}
    ms.insert(1); //{1,1,1,2}
    printMS(ms);

    ms.erase(1); // this erases all the occurences of 1 ance
    printMS(ms);


    ms.insert(1); //{1,2}
    ms.insert(1); //{1,1,2}
    ms.insert(1); //{1,1,1,2}



    int cnt = ms.count(1); //counts the occurence of the given element
    cout<<cnt<<endl; 



    //only a single one erased //by erasing through iterator
    ms.erase(ms.find(1));
    printMS(ms);

    




    //-----Selective erasing------(Just like Slicing)-----//

    //here you wrote ms.find(1) + 2 in the end part of the erase() function. But this will give us an error because only array, vector, and string can store elements in contiguous memory locations, so we can't do +2 and access the element after the first occurrence of 1. 
    
    //way 1
    //ms.erase(ms.find(1), next(ms.find(1), 2));
    

    //or (this is the alternative code for selective erasing)
    //way 2
    auto it = ms.find(1);
    advance(it, 2); // /* Now the iterator is one position ahead of where you want it to be. This is because in the erase() function it takes from the start till one element less than the end that we specified.*/
    ms.erase(ms.find(1), it); // Now we have the iterator in the correct place so it will erase properly and we will be left with only one 1.
    cout<<"Erased Set: ";
    printMS(ms);
    //thus we can do erasing of selective elelemnts we can follow either of the ways


    //using these way no we can delete multiple occurences of an element without deleting the repeated element entirely




    //rest all the functions are same as set

}


int main()
{
    explainMultiSet();
    return 0;
}


/*
Here's a Time Complexity Cheat Sheet for all common functions in a C++ std::multiset, which is typically implemented as a Red-Black Tree (self-balancing BST) — just like set, but allows duplicate elements.

✅ Multiset Time Complexity Cheat Sheet
| **Operation**       | **Time Complexity** | **Explanation**                                                        |
| ------------------- | ------------------- | ---------------------------------------------------------------------- |
| `insert(val)`       | O(log n)            | Inserts a value. Duplicates are allowed.                               |
| `erase(val)`        | O(log n)            | Removes **all** occurrences of the value.                              |
| `erase(iterator)`   | O(1)                | Removes the element at the iterator position.                          |
| `find(val)`         | O(log n)            | Finds **any one** iterator to the value (first found).                 |
| `count(val)`        | O(log n) + k        | Returns number of occurrences of the value. k is number of duplicates. |
| `lower_bound(val)`  | O(log n)            | Returns iterator to **first element ≥ val**.                           |
| `upper_bound(val)`  | O(log n)            | Returns iterator to **first element > val**.                           |
| `equal_range(val)`  | O(log n) + k        | Returns pair of iterators representing the **range of duplicates**.    |
| `size()`            | O(1)                | Returns the number of elements in the multiset.                        |
| `empty()`           | O(1)                | Checks whether the multiset is empty.                                  |
| `clear()`           | O(n)                | Removes all elements.                                                  |
| `begin()` / `end()` | O(1)                | Access start or end iterator.                                          |



🧠 Key Points:
Multiset allows multiple instances of equal elements, unlike set.

Internally uses a Red-Black Tree, so most operations are O(log n).

Useful when frequency of elements matters but order must be maintained.

Iterators are bidirectional, and elements are stored in sorted order.

🧾 Summary Table
Operation	Time Complexity
Insert	O(log n)
Erase (by key)	O(log n)
Erase (iterator)	O(1)
Find	O(log n)
Count	O(log n + k)
Lower Bound	O(log n)
Upper Bound	O(log n)
Equal Range	O(log n + k)
Size	O(1)
Empty	O(1)
Clear	O(n)

*/
