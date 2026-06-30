You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
 


class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};

    bool bfs(int row, int col,
             vector<vector<int>>& grid1,
             vector<vector<int>>& grid2,
             vector<vector<bool>>& vis) {

        int n = grid1.size();
        int m = grid1[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = true;

        bool isSubIsland = true;

        while (!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            // If this land cell is water in grid1,
            // then this island cannot be a sub-island.
            if (grid1[i][j] == 0)
                isSubIsland = false;

            for (auto dir : directions) {

                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < n &&
                    j_ >= 0 && j_ < m &&
                    !vis[i_][j_] &&
                    grid2[i_][j_] == 1) {

                    vis[i_][j_] = true;
                    q.push({i_, j_});
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && grid2[i][j] == 1) {

                    if (bfs(i, j, grid1, grid2, vis))
                        count++;
                }
            }
        }

        return count;
    }
};
