You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

class Solution {
public:
    int max_area = 0;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};

    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        int area = 1;

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

                    if(!vis[i_][j_] && grid[i_][j_] == 1){
                        q.push({i_,j_});
                        vis[i_][j_] = true;

                        area++;
                     }
                }
            }
        }

        max_area = max(max_area,area);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(!vis[i][j] && grid[i][j] == 1) bfs(i,j,grid,vis);
                
            }
        }

        return max_area;
    }
};
