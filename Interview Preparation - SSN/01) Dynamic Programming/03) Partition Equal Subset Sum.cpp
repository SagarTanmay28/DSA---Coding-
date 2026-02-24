// Recursion + Memoization 
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

// Bottom Up 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return false;

        sum = sum / 2;
        
        // dp[i][s] = can we make sum 's' using first 'i' elements
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // Base case: sum = 0 is always possible (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= sum; s++) {
                // Leave current element
                dp[i][s] = dp[i - 1][s];
                
                // Take current element if possible
                if (s >= nums[i - 1]) {
                    dp[i][s] = dp[i][s] || dp[i - 1][s - nums[i - 1]];
                }
            }
        }
        
        return dp[n][sum];
    }
};
