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

    int kruskal(int n, vector<vector<int>>& edges) {

        // Initialize DSU
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Sort by weight
        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        int mstWeight = 0;
        int edgesUsed = 0;

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // If u and v are already connected,
            // adding this edge creates a cycle
            if (find(u) == find(v))
                continue;

            // Add edge to MST
            Union(u, v);

            mstWeight += wt;
            edgesUsed++;

            // MST contains exactly n - 1 edges
            if (edgesUsed == n - 1)
                break;
        }

        return mstWeight;
    }
};
