There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3


class Solution {
public:
    vector<int> parent, rank;

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

        if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else {
            parent[px] = py;
            rank[py]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   // only upper triangle
                if (isConnected[i][j] == 1)
                    Union(i, j);
            }
        }

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                provinces++;
        }

        return provinces;
    }
};
