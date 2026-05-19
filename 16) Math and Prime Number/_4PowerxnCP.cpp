#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

long long power(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)  // if b is odd
            res = res * x;
        x = x * x;  // square the base
        n >>= 1;    // divide exponent by 2
    }
    return res;
}

int main(){
    long long x = 2;
    long long n = 10;

    cout << power(x,n);
}