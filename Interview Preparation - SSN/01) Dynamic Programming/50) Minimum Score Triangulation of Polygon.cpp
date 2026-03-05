You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.


class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j ,int n, vector<int>& values){
        if(j - i < 2) return 0; // No Triangle can be formed 

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for(int k=i+1;k<j;k++){
            int temp_ans = solve(i,k,n,values) + solve(k,j,n,values) + values[i] * values[j] * values[k];
            
            mini = min(mini,temp_ans);
        }

        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1)); // Initialize member variable

        return solve(0,n-1,n,values);
        
    }
};
