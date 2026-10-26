Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

class Solution {
public:
    int n;
    int m;

    bool dfs(int i, int j, vector<vector<int>>& grid){

        if(i >= n || i < 0 || j >= m || j < 0) return false;

        if(grid[i][j] == 1) return true;

        grid[i][j] = 1;

        bool left  = dfs(i+1,j,grid);
        bool right = dfs(i,j+1,grid);
        bool up    = dfs(i-1,j,grid);
        bool down  = dfs(i,j-1,grid);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    if(dfs(i,j,grid)) ans++;
                }
            }
        }

        return ans;
    }
};
