You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the g rid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis){

        int n = grid.size();
        int m = grid[0].size();

        queue< pair<int,int> > q;
        q.push({row,col});
        vis[row][col] = true;

        bool touchesBoundary = false;
        int cells = 0;

        while(q.size()){

            auto p = q.front();
            q.pop();

            cells++;

            int i = p.first;
            int j = p.second;

            if(i == 0 || i == n-1 || j == 0 || j == m-1) touchesBoundary = true;

            for(auto dir : directions){

                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] == 1 && vis[i_][j_] == false){

                    vis[i_][j_] = true;
                    q.push({i_,j_});
                }
            }
        }

        return touchesBoundary == true ? 0 : cells;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 1 && !vis[i][j]){
                    ans += bfs(i,j,grid,vis);
                }
            }
        }

        return ans;


    }
};
