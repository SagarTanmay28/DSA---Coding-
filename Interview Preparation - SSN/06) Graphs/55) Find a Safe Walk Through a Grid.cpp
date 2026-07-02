You are given an m x n binary matrix grid and an integer health.

You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

 

Example 1:

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.


Example 2:

Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

Output: false

Explanation:

A minimum of 4 health points is needed to reach the final cell safely.


Example 3:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.



Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
2 <= m * n
1 <= health <= m + n
grid[i][j] is either 0 or 1.

class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        ans[0][0] = grid[0][0]; // (0,0) is the starting point 

        deque< pair<int,int> > dq;
        dq.push_front({0,0});

        while(dq.size()){

            auto[r,c] = dq.front();
            dq.pop_front();

            for(auto dir : directions){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){

                    if(ans[nr][nc] > ans[r][c] + grid[nr][nc]){
                        ans[nr][nc] = ans[r][c] + grid[nr][nc];

                        if(grid[nr][nc] == 0) dq.push_front({nr,nc});
                        else dq.push_back({nr,nc});
                    }
                }
            }

        }

        return (health - ans[n-1][m-1] >= 1) ? true : false;

    }
};
