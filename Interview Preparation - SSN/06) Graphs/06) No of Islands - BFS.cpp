class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && vis[i][j] == false) {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while(q.size() > 0) {
            auto front = q.front();
            q.pop();

            int row = front.first, col = front.second;

            if(row > 0) {
                if(vis[row-1][col] == false && grid[row-1][col] == '1') {
                    q.push({row-1, col});
                    vis[row-1][col] = true;
                }
            }

            if((row+1) < m) {
                if(vis[row+1][col] == false && grid[row+1][col] == '1') {
                    q.push({row+1, col});
                    vis[row+1][col] = true;
                }
            }

            if(col > 0) {
                if(vis[row][col-1] == false && grid[row][col-1] == '1') {
                    q.push({row, col-1});
                    vis[row][col-1] = true;
                }
            }

            if((col+1) < n) {
                if(vis[row][col+1] == false && grid[row][col+1] == '1') {
                    q.push({row, col+1});
                    vis[row][col+1] = true;
                }
            }
        }
    }
};
