You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int i, int j, int currSum, vector<vector<int>>& grid, int k,
              vector<vector<vector<int>>>& dp) 
    {
        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m) return 0;

        int rem = currSum % k;

        if (dp[i][j][rem] != -1) 
            return dp[i][j][rem];

        currSum += grid[i][j];

        if (i == n - 1 && j == m - 1) 
            return dp[i][j][rem] = ((currSum % k == 0) ? 1 : 0);

        int right = solve(i, j + 1, currSum, grid, k, dp);
        int down  = solve(i + 1, j, currSum, grid, k, dp);

        return dp[i][j][rem] = (right + down) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();

        // ONLY CHANGE: dp is now 3D (i, j, remainder)
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, -1))
        );

        return solve(0, 0, 0, grid, k, dp);
    }
};
