// Greedy Solution 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(i > maxi) return false;
            maxi = max(maxi,i + nums[i]);
        }
        return true;    
    }
};

// DP Solution 

class Solution {
public:
    bool solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size() - 1) return true;

        if(dp[i] != -1) return dp[i];

        int jumps = nums[i];
        for(int j=1;j<=jumps;j++){
            if(solve(i+j,nums,dp)) return dp[i] = true;
        }

        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        return solve(0,nums,dp);
    }
};
