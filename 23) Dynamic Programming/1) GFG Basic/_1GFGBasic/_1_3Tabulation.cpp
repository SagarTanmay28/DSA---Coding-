// C++ program to find
// fibonacci number using tabulation.
#include <iostream>
#include <vector>
using namespace std;

// *** Using Tabulation Approach - O(n) Time and O(n) Space

// Function for calculating the nth Fibonacci number
int fibo(int n) {
    vector<int> dp(n + 1);

    // Storing the independent values in dp
    dp[0] = 0;
    dp[1] = 1;

    // Using the bottom-up approach
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
  
    return dp[n];
}

int main() {
    int n = 5;
    cout << fibo(n);
    return 0;
}