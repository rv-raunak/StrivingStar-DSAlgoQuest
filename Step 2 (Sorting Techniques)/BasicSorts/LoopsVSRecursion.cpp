#include<iostream>
using namespace std;

void RecursionLoop(int start, int end)
{
    if(start>end) return;
    cout<<start<<endl;
    RecursionLoop(start+1, end);
}
//another variation
void RecursionLoop2(int start, int end)
{
    if(start>end) return;
    cout<<start<<endl;
    start++;
    RecursionLoop(start, end);
}

//it uses backtarcking to print the same ascending order 
//the trick is to write the logic of descending order but use the print statement afterwards
void RecursionLoop3(int start, int end)
{
    if(end<start) return;
    RecursionLoop(start, end-1);
    cout<<end<<endl;
}

void nestedloop(int start, int n)
{
    for(int i = start; i<=n; i++)
    {
        for(int j = start; j<=n; j++)
        {
            cout<<"("<<i<<","<<j<<")"<<" ";
        }
        cout<<endl;
    }
}


//nested loops using Recursion (my way)

void RecursionInsideLoop(int startj, int endj, int starti, int endi)
{
    if(startj>endj) return;
    cout<<"("<<starti<<","<<startj<<")"<<" ";
    RecursionInsideLoop(startj+1, endj, starti, endi);
}

void RecursionOuterLoop(int starti, int endi, int startj, int endj)
{

    if(starti>endi) return;
    RecursionInsideLoop(startj, endj, starti, endi);
    cout<<endl;
    RecursionOuterLoop(starti+1, endi, startj, endj);
}

int main()
{
    int start, end;
    cout<<"Enter start and end respectively: "; 
    cin>>start>>end;

    RecursionOuterLoop(start, end, start, end);
    return 0;
}
















// #include<bits/stdc++.h>
// using namespace std;

// // void loop(int starti, int end)
// // {
// //     if(starti>end) return;
// //     cout<<starti<<endl;
// //     loop(starti+1, end);
// // }

// void innerloop(int starti, int endi, int startj, int endj)
// {
//     if(startj>endj) return;
//     cout<<"("<<starti<<","<<startj<<")"<<" ";
//     innerloop(starti, endi, startj+1, endj);
// }
// void loop(int starti, int endi, int startj, int endj)
// {
//     if(starti>endi) return;
//     innerloop(starti, endi, startj, endj);
//     cout<<endl;
//     loop(starti+1, endi, startj, endj);
// }





// int main()
// {
//     int start, end;
//     cout<<"Enter start: ";
//     cin>>start;

//     cout<<"Enter end: ";
//     cin>>end;

//     loop(start, end, start, end);
//     return 0;
// }
