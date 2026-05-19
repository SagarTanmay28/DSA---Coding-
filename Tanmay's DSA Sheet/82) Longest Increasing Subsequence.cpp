// Approach - 1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i],dp[j]);
            }

            dp[i] += 1;
        }

        int maxi = *max_element(dp.begin(),dp.end());

        return maxi;
    }
};

// Approach - 2

class Solution {
public:
    int LIS(int i, vector<int>& nums, vector<int> &dp){
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int take = 1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j] > nums[i]){
                take = max(take, 1 + LIS(j,nums,dp));
            }
        }

        return dp[i] = take;

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,LIS(i,nums,dp));
        }

        return ans;
        
    }
};
