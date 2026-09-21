#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int timer = 0;

    void dfs(int u, int parent,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<int>& tin,
             vector<int>& low,
             vector<bool>& isAP) {

        visited[u] = true;

        // Discovery time and lowest reachable time
        tin[u] = low[u] = timer++;

        int children = 0;

        for(int &v : adj[u]) {

            // Ignore parent edge
            if(v == parent) {
                continue;
            }

            // Back edge
            if(visited[v]) {

                low[u] = min(low[u], tin[v]);

            }

            // Tree edge
            else {

                dfs(v, u, adj, visited, tin, low, isAP);

                // Update low value using child
                low[u] = min(low[u], low[v]);

                // If u is not root
                if(parent != -1 && low[v] >= tin[u]) {

                    isAP[u] = true;
                }

                children++;
            }
        }

        // If u is root
        if(parent == -1 && children > 1) {

            isAP[u] = true;
        }
    }


    vector<int> articulationPoints(
        int V,
        vector<vector<int>>& edges) {

        // Build adjacency list
        vector<vector<int>> adj(V);

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);

        vector<int> tin(V, -1);
        vector<int> low(V, -1);

        vector<bool> isAP(V, false);

        // Graph may be disconnected
        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                dfs(i, -1,
                    adj,
                    visited,
                    tin,
                    low,
                    isAP);
            }
        }

        vector<int> ans;

        for(int i = 0; i < V; i++) {

            if(isAP[i]) {
                ans.push_back(i);
            }
        }

        // No articulation point
        if(ans.empty()) {
            return {-1};
        }

        return ans;
    }
};
