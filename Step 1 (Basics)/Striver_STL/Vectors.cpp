
/*
| Operation                          | Time Complexity         | Notes                                                |
| ---------------------------------- | ----------------------- | ---------------------------------------------------- |
| `v[i]` / `v.at(i)`                 | ✅ O(1)                  | Direct access by index (random access array)         |
| `v.front()` / `v.back()`           | ✅ O(1)                  | Access first or last element                         |
| `v.push_back(x)`                   | ✅ O(1) amortized        | Fast unless resizing (then O(n)); adds to end        |
| `v.pop_back()`                     | ✅ O(1)                  | Removes last element                                 |
| `v.insert(pos, x)`                 | ❌ O(n)                  | May shift elements to the right                      |
| `v.erase(pos)`                     | ❌ O(n)                  | Shifts remaining elements left                       |
| `v.clear()`                        | ✅ O(n)                  | Destroys all elements                                |
| `v.size()`                         | ✅ O(1)                  | Returns current size                                 |
| `v.capacity()`                     | ✅ O(1)                  | Shows allocated space (may be more than size)        |
| `v.reserve(n)`                     | ✅ O(n)                  | Preallocates memory to avoid frequent resizing       |
| `v.resize(n)`                      | ✅ O(n)                  | Adjusts size; may construct/destroy elements         |
| `v.shrink_to_fit()`                | ❌ O(n) (not guaranteed) | Reduces capacity to match size (optional)            |
| `std::find(v.begin(), v.end(), x)` | ❌ O(n)                  | Linear search for element                            |
| `std::sort(v.begin(), v.end())`    | ✅ O(n log n)            | Uses introsort (quick + heap + insertion sort combo) |

📌 Bonus Notes:
vector offers random access — use it when you need fast reads by index. 
Random access refers to the ability to access any element directly by its index in constant time, O(1).

Avoid insert() or erase() in the middle — shifting makes them expensive.

Best use case: append-only or read-heavy data.


*/

#include<iostream>
#include<vector>
using namespace std;

//first container that we'll be learning
//Vectors V/S Arrays
/*
Earlier arrays were used to store multiple values however array has a constant size which cannot be modified after being assigned

->Vector is a container which is dynamic in nature as we can modify its size

->it stores elements in the similar fashion as the array does i.e. in continous locations in the memory

-> if there is a requirement where you don't know the size of the data structure then you can use vectors for that

//study the functions of vector in much detail as these functions will be similar in all other containers Queue, List, map, set etc.
*/

void print_vector(vector<int> &vec)
{
    for(int x: vec){cout<<x<<" ";}
    cout<<endl;
}
void explainVector()
{


    //--------------------vector declaration------------------//
    vector<int> v;  //creates an empty vector

    v.push_back(1);  //"Adds a new value in the empty vector container"
    v.push_back(2);
    v.emplace_back(3); //same as push_back but its generally considered faster //it dynamically increases its size and adds the value (ig push_back does the same too, find out)
    print_vector(v);

    vector<pair<int, int>>vec;
    vec.push_back({1,2}); //in order insert a pair you must enclose it into curly brackets
    vec.emplace_back(1,2);  //here no need for brackets as it automatically assumes it to be a pair by itself and inserts it by its own
    //print_vector(vec);    

    //declaring same value but multiple times in the vector
    vector<int>v2(5, 100);    //this creates a container conatining 5 instances of 100 {100, 100, 100, 100, 100}
    //this is just the initial size we can increase it using push_back
    print_vector(v2);

    vector<int>v3(5); //this declares and creates a container of inital size 5 and all the values maybe 0 or garbage value (depending on the compiler)
    //this is just the initial size we can increase it using push_back
    print_vector(v3);


    vector<int>Copy1(v2); //this creates a new sepearate copy of v2 vector named as Copy1 //these both are not the same but different
    print_vector(Copy1);

    //------------accessing elements in a vector-------------//
    //---using indexing---//

    cout<<v[0]<<" "<<v.at(1)<<endl;   
    //at is generally not used it works same as accessing index
    cout<<v.back()<<" "<<endl; //access the last element




    //using ----- iterators
    //iterator points to the memory location at where the element is stored in the vector
    //there are four types of iterators given below (and the former two are mostly used)

    vector<int>::iterator it = v.begin();  
    //it starts with whatever datatype you have to access from the vector 
    //now iterator is set to v.begin() means that it points at the address of the first element in the memory that is contained in the vector.
    cout<<*it<<" ";
    it++;  //iterator here moves to the next memory address by 1 unit
    cout<<*(it)<<" ";
    it=it+2;  //it actually goes beyond the indexing and thus accesses 0
    cout<<*(it)<<endl;
     
    //now there are more iterators apart from begin()

    vector<int>:: iterator it2 = v.end();  
    //this points to the memory location just after the last element (and not at last element), we must do i-- to access the last element and then the other elements of the container

    //the rest two iterators are never used by its good to know about them
    vector<int>::reverse_iterator it3 = v.rend(); //reverse-end  (end means right after but since this is reverse so it goes to right after the first element (which actually means before))
    //this will point to the memory location just before the first element and you must i++ to access the first element 
    
    vector<int>::reverse_iterator it4 = v.rbegin(); //reverse-begin (reverse of begin)
    //this will point to the memory location of the last element and it also iterates in the reverse way(right to left) you must i++ to access rest elements. 





    //---------printing a vector using loops and itertors------------------//

    cout<<endl<<"<-----------------Loop----------------->"<<endl;
    //using the loops----->
    for(int i = 0; i<3; i++)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<endl<<"-----------------Iterators--------------"<<endl;

    //using the iterators
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++)  //it != v.end() works fine as well
    {
        cout<< *(it) <<" ";
    }

    cout<<endl;

    //now there is another variation for the iterator
    //when you write 'auto' then it automatically assigns the datatype as vector iterator //so this shortens the work and the syntax 
    //auto means auto-assignation
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout<<*(it)<<" ";
    }

    cout<<endl; 

    cout<<"-----------using the for-each loop------------"<<endl;

    //remember that here auto x is not the iterator it is the vector value itself

    //int x : v works fine as every value stored in the vector is 'int'
    for(auto x : v)   
    {
        cout<<x<<" ";
    }



    //deletion in a vector
    cout<<endl<<"-----------deletion in a vector------------"<<endl;
    vector<int> s={10,20,12,13,14,19,20};
    

    //using the erase function for single element
    //here we need to provide erase function with the location of the address of the element thus we do: [vector].erase([iterator]);
    s.erase(s.begin()+1);
    //---it deletes 20 and then re-shuffles the vector as {10,12,13,14,19,20}

    for(auto x : s) cout<<x<<" "; //for checking


    //deleting muliple elements 
    cout<<endl<<"-----------deleting muliple elements--------------\n"; 
    s.erase(s.begin()+2, s.begin()+5); //{10,12,20} 
    //here it works like python range func s.erase[starting, end+1]
    //since I needed to delete from 13 so I wrote s.begin()+2 (its like (0 + 2 as you can consider s.begin() as 0)
    //and I had to delete till 19 so I have to give sp I had to do s.(begin() + 4) + 1 ----its just like zero based indexing as end is not included but the start is included.
    
    for(auto x : s) cout<<x<<" "; //for checking
    
    
    
    //inserting elements in a vector
    cout<<endl<<"-----------inserting elements in a vector--------------\n"; 

    vector<int>w(2,100); //{100, 100}

    w.insert(w.begin(), 300); //inserting 300 at the start of the vector
    w.insert(w.begin()+1, 3, 50); //this will insert three 50s starting from indexing 1  
    //insert(index [memory location from begin()], no. of elements, element)
    for(auto x : w) cout<<x<<" "; //for checking


    //inserting a vector into a vector (hardly required)
    vector<int> w1(2, 25); //{25, 25}
    w.insert(w.begin(), w1.begin(), w1.end());  //here the insert syntax is changed a bit
    cout<<"\n-------------------inserting vector into vector-------------------\n";
    for(auto x : w) cout<<x<<" "; //for checking



    cout<<"\n\nfinding the size of the vector\n";
    cout<< w.size(); 

    cout<<"\n\npopping the last element of the vector\n";
    w.pop_back(); //remember it returns nothing //so you can't store or print it

    for(auto x : w) cout<<x<<" "; //for checking



    cout<<"\n\nswapping 2 vectors\n";
    vector<int> x1={10,20};
    vector<int> x2={30,40};
    x1.swap(x2);
    for(auto x : x1) cout<<x<<" "; //for checking
    cout<<endl;
    for(auto x : x2) cout<<x<<" "; //for checking
    
    v.clear(); //this clears all the elements without deleting the vector   //erases the entire vector
    cout<<"\n\nNo. of elements after clearing the vector v: ";
    cout<<v.size();  //no element is left in this v vector now that's why the size is 0
    
    //empty vector status checker 
    cout<<"\n\nIs vector v empty: "<<v.empty()<<endl; 
    //here 1 means true
    //if even 1 element was there then then it would have printed 0 (or false)
    cout<<"Is vector x1 empty: "<<x1.empty()<<endl;
     


    ///-------------so these are the funcs which are generally required by the vector---------------///



    





}
int main()
{
    explainVector();
    return 0; 
}


