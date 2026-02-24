// Recursion + Memoization 
class Solution {
public:
    int solve(int amount, vector<int>& coins, int i, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(amount < 0 || i >= coins.size()) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = solve(amount-coins[i],coins,i,dp);
        int leave = solve(amount,coins,i+1,dp);

        return dp[i][amount] = take + leave;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};

// Bottom Up - 2D
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        // Base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;   // amount = 0
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                
                if(coins[i-1] <= j) {
                    dp[i][j] = dp[i][j - coins[i-1]]  // Take
                               + dp[i-1][j];          // Leave
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};

// Bottom Up - 1D

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};
