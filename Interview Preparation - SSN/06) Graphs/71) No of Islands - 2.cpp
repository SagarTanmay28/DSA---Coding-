Problem Statement: You are given an n, m which means the row and column of the 2D matrix, and an array of 
size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. 
  Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) 
and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]]
from sea to island. Return how many islands are there in the matrix after each operation. You need to return an array of size k.

Note: An island means a group of 1s such that they share a common side.

  class Solution {
public:

    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {

        parent.resize(n * m);
        rank.resize(n * m, 0);

        for (int i = 0; i < n * m; i++)
            parent[i] = i;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        vector<int> ans;

        int count = 0;

        for (auto op : operators) {

            int row = op[0];
            int col = op[1];

            // Already an island
            if (vis[row][col]) {
                ans.push_back(count);
                continue;
            }

            // Convert water to land
            vis[row][col] = true;
            count++;

            int node = row * m + col;

            // Check 4 directions
            for (auto dir : directions) {

                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m) {

                    if (vis[newRow][newCol]) {

                        int newNode = newRow * m + newCol;

                        // Different islands
                        if (find(node) != find(newNode)) {

                            Union(node, newNode);

                            count--;
                        }
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};

