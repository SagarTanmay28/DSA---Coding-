class Solution {
public:
    int paths(vector<vector<int>>& nums, int r, int c, vector<vector<int>>& dp){
        int n = nums.size();
        int m = nums[0].size();

        if(r >= n || c >= m) return 0;
        if(nums[r][c] == 1) return 0;
        if(r == n-1 && c == m-1) return 1;

        if(dp[r][c] != -1) return dp[r][c];

        int right = paths(nums,r+1,c,dp);
        int down = paths(nums,r,c+1,dp);

        return dp[r][c] = right + down; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        int ans = paths(nums,0,0,dp);
        
        return ans;
        
    }
};
