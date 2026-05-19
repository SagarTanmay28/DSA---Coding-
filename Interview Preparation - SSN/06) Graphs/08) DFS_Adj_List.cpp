void dfs(int i, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[i] = true;

    for(auto j : adj[i]) {
        if(vis[j] == false) {
            dfs(j, vis, adj);
        }
    }
}
