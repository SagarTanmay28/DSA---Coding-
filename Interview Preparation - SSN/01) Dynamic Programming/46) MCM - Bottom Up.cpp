// Bottom Up 



int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int len = 2; len < n; len++){
        for(int i = 1; i < n - len + 1; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j],
                               dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j]);
            }
        }
    }
    
    return dp[1][n-1];
}


// Explanation :: 

Top-Down → Bottom-Up (MCM)

solve(i, j) → min cost to multiply matrices from i to j

Base case:

i >= j → 0

Recurrence:

dp[i][j] = min(
    dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]
)
🔹 Key Observation

(i, j) depends on smaller ranges

(i, k)

(k+1, j)

So compute smaller lengths first

🔹 Bottom-Up Logic

Create dp[n][n]

Initialize dp[i][i] = 0

Iterate by chain length:

for len = 2 to n-1

For each i:

j = i + len - 1

Apply same recurrence using DP table

🔹 Order of Filling

Diagonal → 0

Then length 2

Then length 3

Then length 4 …

🔹 Complexity

Time → O(N³)

Space → O(N²)
