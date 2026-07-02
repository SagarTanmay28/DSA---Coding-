You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:


Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:


Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0



class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> que;
        
        int i = 0, j = 0;
        que.push({i, j, k});
        
        bool visited[41][41][1601];
        //vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k)));
        memset(visited, false, sizeof(visited));
        
        int steps = 0;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                vector<int> temp = que.front();
                que.pop();
                int curr_i   = temp[0];
                int curr_j   = temp[1];
                int obs = temp[2];
                
                if(curr_i == m-1 && curr_j == n-1)
                    return steps;
                
                for(vector<int> &dir : directions) {
                    
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    
                    if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                        continue;
                    
                    if(grid[new_i][new_j] == 0 && !visited[new_i][new_j][obs]) {
                        que.push({new_i, new_j, obs});
                        visited[new_i][new_j][obs] = true;
                    } else if(grid[new_i][new_j] == 1 && obs > 0 && !visited[new_i][new_j][obs-1]) {
                        que.push({new_i, new_j, obs-1});
                        visited[new_i][new_j][obs-1] = true;
                    }
                }
                
            }
            steps++;
        }
        
        return -1;
    }
};
