There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

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

            // Parent edge
            if(v == parent) {
                continue;
            }

            // Back edge
            if(visited[v]) {

                low[u] = min(low[u], tin[v]);

            }

            // Unvisited child
            else {

                dfs(v, u, adj, visited, tin, low, bridges);

                // Get the lowest reachable time from child
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

        // Build adjacency list
        vector<vector<int>> adj(n);

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


        // Start DFS
        dfs(0, -1, adj, visited, tin, low, bridges);


        return bridges;
    }
};
