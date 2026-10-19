Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally 
connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Approach - 1 :: 


class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        // If we go outside the grid, this island is not closed
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false;
        }

        // Water: no land to explore
        if (grid[r][c] == 1) {
            return true;
        }

        // Mark this land cell as visited
        grid[r][c] = 1;

        // Explore all four directions
        bool up    = dfs(grid, r - 1, c);
        bool down  = dfs(grid, r + 1, c);
        bool left  = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};


Approach 2 :: 


class Solution {
public:
    int m, n;

    vector<vector<int>> directions = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1}    // Right
    };

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        // Out of bounds means the island is not closed
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return false;
        }

        // Water
        if (grid[r][c] == 1) {
            return true;
        }

        // Mark visited
        grid[r][c] = 1;

        bool isClosed = true;

        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (!dfs(grid, nr, nc)) {
                isClosed = false;
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};


  
