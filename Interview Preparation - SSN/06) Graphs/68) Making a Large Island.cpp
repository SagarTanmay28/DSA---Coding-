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

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        Size.assign(n * n, 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i;

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        // Build islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    continue;

                int node = i * n + j;

                for (auto &d : dir) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                        grid[ni][nj] == 1) {

                        int adj = ni * n + nj;
                        Union(node, adj);
                    }
                }
            }
        }

        int ans = 0;

        // Try flipping every 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1)
                    continue;

                unordered_set<int> st;
                int curr = 1;

                for (auto &d : dir) {

                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                        grid[ni][nj] == 1) {

                        int root = find(ni * n + nj);

                        if (st.insert(root).second)
                            curr += Size[root];
                    }
                }

                ans = max(ans, curr);
            }
        }

        // Handle all-1 grid
        for (int i = 0; i < n * n; i++)
            ans = max(ans, Size[find(i)]);

        return ans;
    }
};
