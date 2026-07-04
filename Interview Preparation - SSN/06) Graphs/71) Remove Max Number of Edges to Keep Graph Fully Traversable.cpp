Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

Example 1:



Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
Example 2:



Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
Example 3:



Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.



class DSU {
public:
    vector<int> parent, Rank;
    int components;

    DSU(int n) {
        parent.resize(n + 1);
        Rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        components = n;
    }

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

        components--;

        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU alice(n);
        DSU bob(n);

        int usedEdges = 0;

        // Process type 3 edges first
        for (auto &e : edges) {

            if (e[0] != 3)
                continue;

            bool a = alice.Union(e[1], e[2]);
            bool b = bob.Union(e[1], e[2]);

            if (a || b)
                usedEdges++;
        }

        // Alice's edges
        for (auto &e : edges) {

            if (e[0] != 1)
                continue;

            if (alice.Union(e[1], e[2]))
                usedEdges++;
        }

        // Bob's edges
        for (auto &e : edges) {

            if (e[0] != 2)
                continue;

            if (bob.Union(e[1], e[2]))
                usedEdges++;
        }

        if (alice.components != 1 || bob.components != 1)
            return -1;

        return edges.size() - usedEdges;
    }
};
