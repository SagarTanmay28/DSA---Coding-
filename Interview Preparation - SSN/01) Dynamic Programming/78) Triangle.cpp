Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10

// Accepted 
  class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t = triangle;

        for(int row = n - 2; row >= 0; row--){
            for(int col = 0; col <= row; col++){
                t[row][col] += min(t[row+1][col],t[row+1][col+1]);
            }
        }

        return t[0][0];
        
    }
};

// T.L.E
class Solution {
public:
    int helper(vector<vector<int>>& triangle, int r, int c, vector<vector<int>>& dp){
        int n = triangle.size();

        if(r == n-1) return triangle[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        long long first = triangle[r][c] + (long long)helper(triangle,r+1,c,dp);
        long long second = triangle[r][c] + (long long)helper(triangle,r+1,c+1,dp);

        return dp[r][c] = min(first,second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return helper(triangle,0,0,dp);
        
    }
};
