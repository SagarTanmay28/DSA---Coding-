You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.



class Solution {
public:

    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    int n;

    int bfs(int row, int col, vector<vector<int>>& grid, int id) {

        queue<pair<int, int>> q;
        q.push({row, col});

        grid[row][col] = id;

        int size = 0;

        while (q.size()) {

            auto front = q.front();
            q.pop();

            int i = front.first;
            int j = front.second;

            size++;

            for (auto dir : directions) {

                int newRow = i + dir[0];
                int newCol = j + dir[1];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 1) {

                    grid[newRow][newCol] = id;

                    q.push({newRow, newCol});
                }
            }
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size();

        // island id -> island size
        unordered_map<int, int> islandSize;

        int id = 2;

        // Find all islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    int size = bfs(i, j, grid, id);

                    islandSize[id] = size;

                    id++;
                }
            }
        }

        int ans = 0;

        // Case: don't change any 0
        for (auto it : islandSize) {
            ans = max(ans, it.second);
        }

        // Try changing every 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] != 0)
                    continue;

                int size = 1;

                // Store unique island IDs
                unordered_set<int> seen;

                for (auto dir : directions) {

                    int newRow = i + dir[0];
                    int newCol = j + dir[1];

                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] > 1) {

                        int id = grid[newRow][newCol];

                        if (seen.find(id) == seen.end()) {

                            seen.insert(id);

                            size += islandSize[id];
                        }
                    }
                }

                ans = max(ans, size);
            }
        }

        return ans;
    }
};
