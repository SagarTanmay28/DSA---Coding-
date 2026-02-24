// Recursion + Memoization 
class Solution { // Learning -> Offset 
public:
    int solve(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(i >= nums.size()){
            return (sum == target);
        }

        if(dp[i][sum + 1000] != -1) return dp[i][sum + 1000];
        
        int take_positive = solve(i+1,sum + nums[i],nums,target,dp);
        int take_negative = solve(i+1,sum - nums[i],nums,target,dp);

        return dp[i][sum + 1000] = take_positive + take_negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));
        return solve(0,0,nums,target,dp);
    }
};

// Bottom up 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int total_sum = 0;
        
        for(int x : nums)
            total_sum += x;
        
        // Edge cases
        if(total_sum < abs(target) || (total_sum + target) % 2 != 0)
            return 0;
        
        int sum = (total_sum + target) / 2;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        // Initialization
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};
