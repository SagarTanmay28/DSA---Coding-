#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

long long power(long long x, long long n, long long MOD) {
    long long res = 1;
    x = x % MOD;
    while (n > 0) {
        if (n & 1)  // if b is odd
            res = (res * x) % MOD;
        x = (x * x) % MOD;  // square the base
        n >>= 1;    // divide exponent by 2
    }
    return res;
}

int main(){
    long long x = 2;
    long long n = 10;
    long long MOD = 1e9 + 7;

    cout << power(x,n,MOD);
}