#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int countDigits(int n){ // Time Complexity: O(log10N + 1)
    
    int count = 0;
    while(n > 0){

        count++;
        n = n / 10;
    }
    
    return count;

}
int countDigitss(int n){ // Time Complexity: O(1)
    
   int count = (int)(log10(n)+1);
    return count;
    
}



int main() {
    int N = 329823;
    cout << "N: "<< N << endl;
    int digits = countDigits(N);
    int digits2 = countDigitss(N);
    cout << "Number of Digits in N: "<< digits << endl;
    cout << "Number of Digits in N: "<< digits2 << endl;
    return 0;
}

                                
                            