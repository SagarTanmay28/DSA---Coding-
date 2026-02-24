// Recursion + Memoization

class Solution {
  public:
    int solve(int i, int n, vector<int>& price, vector<int>& nums, vector<vector<int>>& dp){
        if(n == 0 || i >= price.size()) return 0;
        
        if(dp[i][n] != -1) return dp[i][n];
        
        int take = 0;
        if(nums[i] <= n){
            take = price[i] + solve(i,n-nums[i],price,nums,dp);
        }
        
        int leave = solve(i+1,n,price,nums,dp);
        
        return dp[i][n] = max(take,leave);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(0,n,price,nums,dp);
    }
};

// Bottom Up 
class Solution {
public:

    int cutRod(vector<int> &price) {
        
        int n = price.size();
        
        // lengths array (1 to n)
        vector<int> length(n);
        for(int i = 0; i < n; i++)
            length[i] = i + 1;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // Build DP table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                
                if(length[i-1] <= j) {
                    dp[i][j] = max(
                        price[i-1] + dp[i][j - length[i-1]],  // Take (same row)
                        dp[i-1][j]                             // Leave
                    );
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};
