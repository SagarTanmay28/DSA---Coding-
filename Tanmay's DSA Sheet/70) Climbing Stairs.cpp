// Approach 1 

class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

// Approach 2 

class Solution {
public:
    int ways(int n, int idx, vector<int>& dp){
        if(idx == n) return 1;
        if(idx > n) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = ways(n,idx+1,dp) + ways(n,idx+2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return ways(n,0,dp);
        
    }
};
