class Solution {
public:
    int robMax(vector<int>& nums, int i, int j, vector<int>& dp){

        if(i > j) return 0;

        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + robMax(nums,i+2,j,dp);
        int skip = robMax(nums,i+1,j,dp);

        return dp[i] = max(steal,skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp1(n,-1),dp2(n,-1);
        return max(robMax(nums,0,n-2,dp1),robMax(nums,1,n-1,dp2));
        
    }
};
