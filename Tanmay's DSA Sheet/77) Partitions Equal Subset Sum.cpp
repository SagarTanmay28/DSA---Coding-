class Solution {
public:
    bool check(vector<int>& nums, int idx, int sum, int total, vector<vector<int>>& dp){
        if(sum == total) return true;
        if(sum > total) return false;
        if(idx == nums.size()) return false;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        bool take = check(nums,idx+1,sum+nums[idx],total,dp);
        bool leave = check(nums,idx+1,sum,total,dp);

        return dp[idx][sum] = take || leave;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        // Total Sum;
        int total = 0;
        for(int i=0;i<n;i++) total += nums[i];

        // if sum is odd then we cant partition into equal sum 
        if(total % 2 != 0) return false;
        
        vector<vector<int>> dp(n,vector<int>((total/2)+1,-1));
       
        return check(nums,0,0,total/2,dp);
        
    }
};
