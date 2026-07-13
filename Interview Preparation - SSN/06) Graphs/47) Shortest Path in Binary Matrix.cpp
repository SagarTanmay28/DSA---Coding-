Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1



class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        if(n == 1)
            return 1;

        vector<vector<int>> vis(n,vector<int>(m,-1));
        vis[0][0] = 1;

        queue< pair<int,int> > q;
        q.push({0,0});

        while(q.size()){

            auto p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            for(auto dir : directions){

                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && j_ >= 0 && i_ < n && j_ < m && grid[i_][j_] == 0 && vis[i_][j_] == -1){

                    vis[i_][j_] = vis[i][j] + 1;
                    q.push({i_,j_});

                     if(i_ == n-1 && j_ == m-1)
                        return vis[i_][j_];
                }
            }
        }

        return -1;
        
    }
};
