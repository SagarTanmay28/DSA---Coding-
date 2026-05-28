class Solution {
public:

    int spanningTree(int V, vector<vector<int>>& edges) {

        // adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for (auto it : edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // {weight, node}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<bool> vis(V, false);

        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int wt = top.first;
            int node = top.second;

            if (vis[node] == true)
                continue;

            vis[node] = true;

            sum += wt;

            for (auto it : adj[node]) {

                int adjNode = it.first;
                int edgeWt = it.second;

                if (vis[adjNode] == false) {

                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return sum;
    }
};
