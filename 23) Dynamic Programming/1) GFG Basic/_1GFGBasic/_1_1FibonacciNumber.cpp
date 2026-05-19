#include <bits/stdc++.h>
using namespace std;

// T.C = O(2^n);

// Function to find nth fibonacci number
int fib(int n) {
    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 5;
    cout << fib(n);
    return 0;
}