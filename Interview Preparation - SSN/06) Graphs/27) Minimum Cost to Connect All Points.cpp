You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

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

        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[px] = py;
            rank[py]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // {cost, u, v}
        vector<vector<int>> edges;

        // Create all possible edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int cost = abs(points[i][0] - points[j][0])
                         + abs(points[i][1] - points[j][1]);

                edges.push_back({cost, i, j});
            }
        }

        // Sort edges by cost
        sort(edges.begin(), edges.end());

        // Initialize DSU
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int ans = 0;
        int edgesUsed = 0;

        // Kruskal
        for (auto &edge : edges) {

            int cost = edge[0];
            int u = edge[1];
            int v = edge[2];

            // Already connected -> cycle
            if (find(u) == find(v))
                continue;

            // Connect them
            Union(u, v);

            ans += cost;
            edgesUsed++;

            // MST needs n - 1 edges
            if (edgesUsed == n - 1)
                break;
        }

        return ans;
    }
};
