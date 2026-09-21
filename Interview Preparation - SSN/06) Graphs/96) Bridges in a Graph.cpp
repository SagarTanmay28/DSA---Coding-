class Solution {
public:

    int timer = 0;

    void dfs(int u, int parent,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<int>& tin,
             vector<int>& low,
             vector<vector<int>>& bridges) {

        visited[u] = true;

        tin[u] = low[u] = timer++;

        for(int &v : adj[u]) {

            // Don't immediately go back to parent
            if(v == parent)
                continue;

            // Back edge
            if(visited[v]) {

                low[u] = min(low[u], tin[v]);

            }

            // Tree edge
            else {

                dfs(v, u, adj, visited, tin, low, bridges);

                low[u] = min(low[u], low[v]);

                // Bridge condition
                if(low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        // Build graph
        for(auto &edge : connections) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        vector<int> tin(n, -1);
        vector<int> low(n, -1);

        vector<vector<int>> bridges;

        dfs(0, -1, adj, visited, tin, low, bridges);

        return bridges;
    }
};
