#include <iostream>
using namespace std;

void printPattern(int n) {
    int odd = 1, even = 2; 

    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= i; j++) { 
            if (i % 2 == 1) { 
                cout << odd << " ";
                odd += 2; 
            } 
            else { 
                cout << even << " ";
                even += 2; 
            } 
        } 
        cout << endl;
    }
}

int main() {
    int num;
    cout << "Enter Number: ";
    cin >> num;
    printPattern(num);
    return 0;
}
