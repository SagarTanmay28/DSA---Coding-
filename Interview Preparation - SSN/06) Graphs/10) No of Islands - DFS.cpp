// Clean Code :: 
class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = true;

        // 4 directions 
        for(auto dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if((i_ >= 0 && i_ < n) && (j_ >= 0 && j_ < m)){

                if(!vis[i_][j_] && grid[i_][j_] == '1'){
                    dfs(i_,j_,grid,vis);
                }
            }
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return count;
    }
};


// Solution - 2

int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && vis[i][j] == false) {
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();
        vis[i][j] = true;

        if(i-1 >= 0 && grid[i-1][j] == '1' && vis[i-1][j] == false)
            dfs(i-1, j, grid, vis);

        if(i+1 <= m-1 && grid[i+1][j] == '1' && vis[i+1][j] == false)
            dfs(i+1, j, grid, vis);

        if(j-1 >= 0 && grid[i][j-1] == '1' && vis[i][j-1] == false)
            dfs(i, j-1, grid, vis);

        if(j+1 <= n-1 && grid[i][j+1] == '1' && vis[i][j+1] == false)
            dfs(i, j+1, grid, vis);
    }
