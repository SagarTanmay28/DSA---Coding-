// Recursion + Memoization 

class Solution {
public:
    int helper(vector<int>& coins, int amount, int i, long long sum, vector<vector<int>>& dp){
        if(sum == amount) return 0;
        if(sum > amount || i >= coins.size()) return INT_MAX;

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = helper(coins,amount,i,sum+coins[i],dp);
        if(take != INT_MAX) take = take + 1;

        int leave = helper(coins,amount,i+1,sum,dp);

        return dp[i][sum] = min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = helper(coins,amount,0,0LL,dp);

        return (ans == INT_MAX) ? -1 : ans;
        
    }
};

// Recursion + Memoization 
class Solution {
public:
    long long helper(vector<int>& coins, int amount, int i, long long sum, vector<vector<int>>& dp){
        if(sum == amount) return 0;
        if(sum > amount || i >= coins.size()) return INT_MAX;

        if(dp[i][sum] != -1) return dp[i][sum];

        long long take = LLONG_MAX;
        if(coins[i] <= amount){
            take = 1 +  helper(coins,amount,i,sum+coins[i],dp);
        }

        long long leave = helper(coins,amount,i+1,sum,dp);

        return dp[i][sum] = min(take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
 
        int ans = helper(coins,amount,0,0LL,dp);
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};

// Bottom Up 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        const int INF = 1e9;
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INF));
        
        // Base case
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                
                if(coins[i-1] <= j) {
                    dp[i][j] = min(
                        1 + dp[i][j - coins[i-1]],  // Take (same row)
                        dp[i-1][j]                  // Leave
                    );
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[n][amount] >= INF) ? -1 : dp[n][amount];
    }
};
