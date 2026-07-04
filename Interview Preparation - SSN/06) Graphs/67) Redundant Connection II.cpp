In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]


class Solution {
public:
    vector<int> parent, Rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (Rank[px] < Rank[py])
            swap(px, py);

        parent[py] = px;

        if (Rank[px] == Rank[py])
            Rank[px]++;

        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> indegree(n + 1, 0);

        vector<int> cand1, cand2;

        // Detect node having two parents
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if (indegree[v] == 0)
                indegree[v] = u;
            else {
                cand1 = {indegree[v], v};
                cand2 = e;
                e[1] = 0;   // Ignore second edge
            }
        }

        parent.resize(n + 1);
        Rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges) {

            if (e[1] == 0)
                continue;

            if (!Union(e[0], e[1])) {

                if (cand1.empty())
                    return e;

                return cand1;
            }
        }

        return cand2;
    }
};
