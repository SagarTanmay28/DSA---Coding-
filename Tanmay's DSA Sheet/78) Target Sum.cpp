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
