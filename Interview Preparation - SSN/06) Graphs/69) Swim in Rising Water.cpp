You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.


// Dijkshtra :: 

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0],0,0});
        dist[0][0] = grid[0][0];

        vector<pair<int,int>> dir = {
            {-1,0},{1,0},{0,-1},{0,1}
        };

        while(!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(i==n-1 && j==n-1)
                return time;

            for(auto &d : dir){

                int ni=i+d.first;
                int nj=j+d.second;

                if(ni<0||nj<0||ni>=n||nj>=n)
                    continue;

                int newTime=max(time,grid[ni][nj]);

                if(newTime<dist[ni][nj]){
                    dist[ni][nj]=newTime;
                    pq.push({newTime,ni,nj});
                }
            }
        }

        return -1;
    }
};


// Binary Search + BFS/DFS

class Solution {
public:
   int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[50][50];
    bool reachable(vector<vector<int>>& grid, int i, int j, int mid) {
        if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid)
            return false;
        
        visited[i][j] = true;
        
        if(i == n-1 && j == n-1)
            return true;
        
        for(vector<int> &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(reachable(grid, new_i, new_j, mid))
                return true;
        }
        
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        
        int l = grid[0][0], r = n*n-1;
        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;
            memset(visited, 0, sizeof(visited));
            
            if(reachable(grid, 0, 0, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
};

// DSU 

class Solution {
public:
    vector<int> parent, Size;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (Size[px] < Size[py])
            swap(px, py);

        parent[py] = px;
        Size[px] += Size[py];
    }

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        Size.assign(n * n, 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i;

        // pos[elevation] = {row, col}
        vector<pair<int, int>> pos(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        vector<vector<bool>> active(n, vector<bool>(n, false));

        vector<pair<int, int>> dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for (int t = 0; t < n * n; t++) {

            auto [i, j] = pos[t];
            active[i][j] = true;

            int node = i * n + j;

            // Union with all active neighbors
            for (auto &d : dir) {
                int ni = i + d.first;
                int nj = j + d.second;

                if (ni < 0 || nj < 0 || ni >= n || nj >= n)
                    continue;

                if (!active[ni][nj])
                    continue;

                int adjNode = ni * n + nj;
                Union(node, adjNode);
            }

            // Check if start and end are connected
            if (active[0][0] &&
                active[n - 1][n - 1] &&
                find(0) == find(n * n - 1)) {
                return t;
            }
        }

        return -1;
    }
};
