// Stack 

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, stack<int>& st) {

        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

// Array 

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& topo) {

        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis, topo);
            }
        }

        // Push after visiting all neighbors
        topo.push_back(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        vector<int> vis(V, 0);
        vector<int> topo;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, topo);
            }
        }

        reverse(topo.begin(), topo.end());

        return topo;
    }
};
