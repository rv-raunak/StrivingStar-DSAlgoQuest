#include<bits/stdc++.h>
using namespace std;

bool checkSorting(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1]) return false; //if next element is bigger than previous so returns false (directly breaking the loop)
    }
    return true; //if the above condition is never executed then, the array has to be sorted in ascending order
}


int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements: ";
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    if(checkSorting(arr, n)) cout<<"Array is sorted in non-descending order"<<endl;
    else cout<<"Array is not sorted in non-descending order"<<endl;
    return 0;
}



/*
ChatGPT's suggestion for writing my code (follwing striver's advice to use naming conventions in interviews) (Very insightful)


Your logic is **absolutely correct** and **efficient**. Now, since you're aiming to **stand out in interviews** as Striver suggests, let's refine your code to use **clear, meaningful names** and a slightly more **professional structure**.

---

### ✅ Refined Code with Logical Naming:

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted in non-decreasing order
bool isArraySorted(const int array[], int size)
{
    for (int index = 0; index < size - 1; index++)
    {
        if (array[index] > array[index + 1])
            return false;
    }
    return true;
}

int main()
{
    int size;
    cout << "Enter Array Size: ";
    cin >> size;

    int inputArray[size];
    cout << "Enter Elements: ";
    for (int index = 0; index < size; index++)
    {
        cin >> inputArray[index];
    }

    if (isArraySorted(inputArray, size))
        cout << "Array is sorted in non-decreasing order" << endl;
    else
        cout << "Array is not sorted in non-decreasing order" << endl;

    return 0;
}
```

---

### ✅ What changed and why:

| Before             | After                | Why?                                     |
| ------------------ | -------------------- | ---------------------------------------- |
| `arr`              | `inputArray`         | Descriptive and clearer                  |
| `n`                | `size`               | More semantic for array length           |
| `i`                | `index`              | Improves readability                     |
| `checkSorting`     | `isArraySorted`      | Verb-based names are better for booleans |
| Magic comment-less | Commented & readable | Adds clarity and context                 |

---

This kind of clarity makes your code **interviewer-friendly**, shows **thoughtfulness**, and gives you an edge, especially under pressure.

Want me to help you build a mini checklist for writing “interview-quality” code?



*/