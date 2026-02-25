// Recursion + Memoization 

class Solution { // Same as LIS 
public:
    int LIS(int i, vector<vector<int>>& nums, vector<int>& dp){
        if(i >= nums.size()) return 0;
        
        if(dp[i] != -1) return dp[i]; // Base Case 

        int take = 1;
        for(int j=i+1;j<nums.size();j++){
            int b = nums[i][1];
            int c = nums[j][0];
            if(c > b){
                take = max(take, 1 + LIS(j,nums,dp));
            }
        }

        return dp[i] = take;
    }
    int findLongestChain(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1);

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,LIS(i,nums,dp));
        }

        return ans;
        
    }
};

// Bottom Up 

int findLongestChain(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<=i-1;j++){
                int b = nums[j][1];
                int c = nums[i][0];
                if(c > b) dp[i] = max(dp[i],dp[j]);
            }

            dp[i] += 1;
        }

        int maxi = *max_element(dp.begin(),dp.end());

        return maxi;
        
}
