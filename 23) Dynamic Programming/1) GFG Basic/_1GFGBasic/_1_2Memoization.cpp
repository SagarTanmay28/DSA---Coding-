#include <iostream>
#include <vector>
using namespace std;

// Using Memoization Approach - O(n) Time and O(n) Space

int fibRec(int n, vector<int> &dp) {
  
    // Base case
    if (n <= 1) {
        return n;
    }

    // To check if output already exists
    if (dp[n] != -1) {
        return dp[n];
    }

    // Calculate and save output for future use
    dp[n] = fibRec(n - 1, dp) + fibRec(n - 2, dp);

    return dp[n];
}

int fib(int n) {
    vector<int> dp(n + 1, -1);
    return fibRec(n, dp);
}

int main() {
    int n = 5;
    cout << fib(n);
    return 0;
}