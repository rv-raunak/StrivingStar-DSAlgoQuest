#include<bits/stdc++.h>
using namespace std;
//the next container that we'll be learning is a map container 
 
//this stores data as key-value pairs having unique keys to differentiate values even if the values are same

//you can think map as a container that stores everything in respect of {key, value}

//Remember that 'Key' can be of any data-type like it can be integer, double, pair etc..(can be anything)
//same goes for Value as it can also be anything (i.e. can be of any datatype)

//Important: Map stores unique keys in sorted order (kinda similar to Set data structure)


void printMap(map<int, int> mpp)
{
    for(map<int, int>::iterator it = mpp.begin(); it!=mpp.end(); it++)
    {
        cout<<"{"<<(*it).first<<","<<it->second<<"} ";
    }
    cout<<endl;

    /*
    You're asking:

    Why does (*it).first work without error, while it.first or *(it.first) gives an error?

    🔍 What's really happening:
    In C++, a map<int, int> stores key-value pairs of type std::pair<const int, int>.

    When you iterate over a map, the iterator (it) is not a pair — it's an object that points to a pair.

    So:

    it → an iterator (like a pointer to a pair)

    *it → the actual pair<const int, int>

    (*it).first → key of the pair ✅

    (*it).second → value of the pair ✅

    🧠 Why (*it).first works:
    Because it does this in steps:

    *it: Dereference the iterator → gives the pair<const int, int>

    .first: Access the key part of that pair

    This is exactly what you're supposed to do.

    ❌ Why it.first doesn't work:
    Because it is an iterator, not a pair.
    And iterators don’t have a first member.
    So it.first or *(it.first) makes no sense to the compiler — and gives an error.

    ✅ Arrow (->) shortcut:
    This is just syntactic sugar:

    cpp
    Copy code
    it->first    // same as (*it).first
    it->second   // same as (*it).second
    So both are valid and give you access to the pair.
        
    🔁 Summary:
    | Code          | Meaning                            | Valid? |
| ------------- | ---------------------------------- | ------ |
| `*it`         | Dereference iterator → gives pair  | ✅      |
| `(*it).first` | Get key from pair                  | ✅      |
| `it->first`   | Same as above (shortcut)           | ✅      |
| `it.first`    | Try to access `.first` on iterator | ❌      |
| `*(it.first)` | Same issue: `it.first` invalid     | ❌      |

    
    */
}


void explainMap()
{
    //defining map
    map<int, int> mpp;  //map<key's datatype, value's dataype> //so here both key and values are integers

    map<int, pair<int, int>>mpp2; //here key is integer and value is of pair type

    map<pair<int, int>,int>mpp3;  //here key is a pair and value is an integer




    //initialization
    mpp[1] = 2;  //mpp[key] = value (just like dictionary in Python)
    //internally it stores {1,2} (as a key-value pair)
    mpp.emplace(3,1);  //stores {3,1} as {key, value} pair
    mpp.insert({2,4}); //another way of storing key-value pair
    //remember that it also stores in sorted order of key, you can also check it by printing it
    printMap(mpp);  //checking if they're stored or not

    mpp3[{2,3}] = 10;
    cout<<mpp3[{2,3}]<<" "<<mpp3.at({2,3})<<endl; //ways of accessing values using key


    //another way of iterating using aut and for each loop (here 'it' is actually a pair not an iterator)
    for(auto it: mpp)
    {
        cout<< it.first << " " << it.second << endl;  //travesing in sorted order of key manner
    }


    //accessing values
    cout<< mpp[2]<<'\n';  //it gives the vale at key '2' i.e. 4 here
    cout<< mpp[5]<<'\n'; //since key is not present so it returns null(however it prints it as 0) as no value would be there



    //if you wanna know the iterator like imagine I want to know the address of particular key I can find that as well
    auto it = mpp.find(3); //here 'it' is an iterator that points at 3 (i.e. a key) (contains the address of its key-value pair)
    cout<<(*it).second<< endl;//prints the value associated with it; 

    // cout<<it<<endl; 
     //this cannot directly print it (find out why)? //my guess is that its because iterator is an object not a value that is pointing at the pair of {key,value}

    //cout<<*it<<endl;   //it also cannot be printed directly as *it is a pair which cannot be directly handled/printed by cout


    it = mpp.find(5); //since this key is not present so it points to mpp.end() i.e. after the last element(key-value pair) outside the map
    cout<<(*it).first<<" "<<(*it).second<<endl;




    //this is the syntax
    //works the same as before
    auto itr = mpp.lower_bound(2);
    auto itr2 = mpp.upper_bound(3);
  


    //erase, swap, size, empty are same as above




}

int main()
{
    explainMap();
    return 0;
}


/*
Here's a Time Complexity Cheat Sheet for C++ std::map, which is implemented as a self-balancing binary search tree (Red-Black Tree).

✅ Map Time Complexity Cheat Sheet
| **Operation**        | **Time Complexity** | **Explanation**                                                                |
| -------------------- | ------------------- | ------------------------------------------------------------------------------ |
| `insert({key, val})` | O(log n)            | Inserts a key-value pair.                                                      |
| `erase(key)`         | O(log n)            | Removes element with given key.                                                |
| `erase(iterator)`    | O(1)                | Deletes the element pointed to by the iterator.                                |
| `find(key)`          | O(log n)            | Finds iterator to the element with the given key.                              |
| `operator[]`         | O(log n)            | Returns reference to value by key; inserts default value if key doesn't exist. |
| `at(key)`            | O(log n)            | Returns reference to value by key; throws exception if key doesn't exist.      |
| `count(key)`         | O(log n)            | Returns 1 if key exists, else 0.                                               |
| `lower_bound(key)`   | O(log n)            | Returns iterator to first key not less than given key.                         |
| `upper_bound(key)`   | O(log n)            | Returns iterator to first key greater than given key.                          |
| `equal_range(key)`   | O(log n)            | Returns a pair of lower and upper bound iterators.                             |
| `size()`             | O(1)                | Number of elements.                                                            |
| `empty()`            | O(1)                | Checks if the map is empty.                                                    |
| `clear()`            | O(n)                | Removes all elements.                                                          |
| `begin()` / `end()`  | O(1)                | Iterators to start/end of map (in sorted order of keys).                       |



🧠 Notes:
std::map keeps keys in sorted order.

Internally uses a Red-Black Tree, so operations are O(log n).

Keys are unique — inserting a duplicate key will not overwrite the existing value (use operator[] or insert_or_assign() for updates).

Iterators are bidirectional.




| Operation            | Time Complexity |
| -------------------- | --------------- |
| Insert               | O(log n)        |
| Erase (key)          | O(log n)        |
| Erase (iterator)     | O(1)            |
| Find                 | O(log n)        |
| Access (`[]` / `at`) | O(log n)        |
| Count                | O(log n)        |
| Lower / Upper Bound  | O(log n)        |
| Equal Range          | O(log n)        |
| Size / Empty         | O(1)            |
| Clear                | O(n)            |




*/