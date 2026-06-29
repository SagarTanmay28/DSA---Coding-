You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.


** Intuition **

Intuition

There are exactly two islands.

Step 1

Find the first island using DFS.

Mark every cell of the first island as visited and push all its cells into a queue.

Now the queue contains all cells of the first island.

Step 2

Run Multi-Source BFS from all cells of the first island simultaneously.

Expand layer by layer over water (0).

The first time you touch the second island (1), the current BFS level is the minimum number of water cells to flip.

Why?

Because BFS explores bridges in increasing order of length.


class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& vis,
             queue<pair<int,int>>& q) {

        int n = grid.size();

        vis[i][j] = true;
        q.push({i, j});

        for (auto &dir : directions) {

            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < n &&
                !vis[ni][nj] &&
                grid[ni][nj] == 1) {

                dfs(ni, nj, grid, vis, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        queue<pair<int,int>> q;

        bool found = false;

        // Find first island
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {

                if (grid[i][j] == 1) {
                    dfs(i, j, grid, vis, q);
                    found = true;
                }
            }
        }

        int level = 0;

        // Multi-source BFS
        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y] = q.front();
                q.pop();

                for (auto &dir : directions) {

                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if (nx >= 0 && nx < n &&
                        ny >= 0 && ny < n &&
                        !vis[nx][ny]) {

                        if (grid[nx][ny] == 1)
                            return level;

                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
