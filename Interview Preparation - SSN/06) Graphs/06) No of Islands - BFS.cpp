// Clean Code :: 

class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = true;
        queue< pair<int,int> > q;
        q.push({row,col});

        while(q.size()){
            pair<int,int> p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;


            // 4 directions 
            for(auto dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if((i_ >= 0 && i_ < n) && (j_ >= 0 && j_ < m)){

                    if(!vis[i_][j_] && grid[i_][j_] == '1'){
                        q.push({i_,j_});
                        vis[i_][j_] = true;
                     }
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
                    bfs(i,j,grid,vis);
                }
            }
        }

        return count;
    }
};

// Solution - 2

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
