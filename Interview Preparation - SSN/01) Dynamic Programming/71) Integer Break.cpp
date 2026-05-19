Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(dp[n] != -1) return dp[n];

        int maxi = 1;

        for(int i=1;i<n;i++){
            int noSplit = i * (n-i);
            int split = i * helper(n-i,dp);
            maxi = max({maxi,noSplit,split});
        }

        return dp[n] = maxi;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);

        return helper(n,dp);
        
    }
};
