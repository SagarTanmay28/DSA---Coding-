// T.L.E 
class Solution {
public:
    int solve(vector<vector<int>>& nums, int r, int c, vector<vector<int>>& dp){
        int n = nums.size();

        // Base Cases
        if(c < 0 || c >= n) return INT_MAX;
        if(r == n-1) return nums[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        int down = solve(nums, r+1, c, dp);
        int left = solve(nums, r+1, c-1, dp);
        int right = solve(nums, r+1, c+1, dp);

        return dp[r][c] = nums[r][c] + min({down, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int minSum = INT_MAX;

        for(int i = 0; i < n; i++){
            minSum = min(minSum, solve(nums, 0, i, dp));
        }

        return minSum;
    }
};

// Accepted 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp = matrix;

        for(int row=1; row<n; row++){

            for(int col=0; col<n; col++){

                int up = dp[row-1][col];
                int left = (col>0)? dp[row-1][col-1] : 1e9;
                int right = (col<n-1)? dp[row-1][col+1] : 1e9;

                dp[row][col] += min({up,left,right});
            }
        }

        int ans = INT_MAX;

        for(int col=0; col<n; col++)
            ans = min(ans , dp[n-1][col]);

        return ans;
    }
};
