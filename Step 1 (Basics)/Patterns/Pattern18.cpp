#include<iostream>
using namespace std;


void alphaTriangle(int n) {
    
    for(int i = 0; i<n; i++)
    {
        char x = 'A' + (n-1); 
        for(int j = i; j>=0; j--)
        {
            cout<<(char)(x-j);
           
        }
        cout<<endl;
    }
}

int main()
{
    alphaTriangle(5);
    return 0; 
}




/*
//chatgpt's logic (good one actually)

#include<iostream>
using namespace std;

void alphaTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << (char)('A' + (n - 1 - j));
        }
        cout << endl;
    }
}

int main() {   //this is main function
    alphaTriangle(5);
    return 0;
}



*/



/*
Striver's logic also good

void pattern18(int N)
{
      // Outer loop for the no. of rows.
      for(int i=0;i<N;i++){
          
          // Inner loop for printing the alphabets from
          // A + N -1 -i (i is row no.) to A + N -1 ( E in this case).
          for(char ch =('A'+N-1)-i;ch<=('A'+N-1);ch++){
              
              cout<<ch<<" ";
          }
          
          // As soon as the letters for each iteration are printed, we move to the
          // next row and give a line break otherwise all letters
          // would get printed in 1 line.
          cout<<endl;
      }
}

*/