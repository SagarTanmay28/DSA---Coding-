Problem Description
You have an m x n grid where each cell contains one of three values:

0: Empty land that you can walk through freely
1: A building that you cannot pass through
2: An obstacle that you cannot pass through
Your goal is to find the best location on an empty land (a cell with value 0) to build a house such that the total travel distance from this house to all buildings is minimized.

Movement is restricted to four directions: up, down, left, and right (no diagonal movement).

The total travel distance is calculated as the sum of the shortest path distances from your chosen location to each building in the grid. The distance between cells is measured using the Manhattan distance (number of steps needed when moving only horizontally or vertically).

Return the minimum total travel distance if it's possible to find such a location that can reach all buildings. If no valid location exists (for example, if some buildings are unreachable from any empty land), return -1.

Example scenario: If there are 3 buildings in the grid and you choose an empty cell, you need to calculate the shortest path from that cell to each of the 3 buildings, then sum these distances. The answer would be the empty cell that gives you the smallest sum.

Key constraints:

You can only build on empty land (cells with 0)
The chosen location must be able to reach ALL buildings in the grid
Obstacles and buildings block movement paths


class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> reach(n, vector<int>(m, 0));

        int buildings = 0;

        // Count buildings
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    buildings++;
            }
        }

        // BFS from every building
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 1)
                    continue;

                queue<pair<int,int>> q;
                vector<vector<bool>> vis(n, vector<bool>(m, false));

                q.push({i, j});
                vis[i][j] = true;

                int level = 0;

                while (!q.empty()) {

                    int sz = q.size();

                    while (sz--) {

                        auto [x, y] = q.front();
                        q.pop();

                        if (grid[x][y] == 0) {
                            dist[x][y] += level;
                            reach[x][y]++;
                        }

                        for (auto &dir : directions) {

                            int nx = x + dir[0];
                            int ny = y + dir[1];

                            if (nx >= 0 && nx < n &&
                                ny >= 0 && ny < m &&
                                !vis[nx][ny] &&
                                grid[nx][ny] == 0) {

                                vis[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }

                    level++;
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0 && reach[i][j] == buildings)
                    ans = min(ans, dist[i][j]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
