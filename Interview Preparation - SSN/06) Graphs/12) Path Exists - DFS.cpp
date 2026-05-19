class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis(n, false);
        return dfs(start, end, adj, vis);
    }

    bool dfs(int node, int end, vector<vector<int>>& adj, vector<bool>& vis) {
        if(node == end) return true;

        vis[node] = true;

        for(int ele : adj[node]) {
            if(!vis[ele]) {
                if(dfs(ele, end, adj, vis)) return true;
            }
        }

        return false;
    }
};
