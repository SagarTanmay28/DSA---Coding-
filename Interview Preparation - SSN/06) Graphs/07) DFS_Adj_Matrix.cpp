void dfs(int i, vector<bool>& vis, vector<vector<int>>& adj) {
    int n = adj.size();
    vis[i] = true;

    for(int j = 0; j < n; j++) {
        if(adj[i][j] == 1 && vis[j] == false) {
            dfs(j, vis, adj);
        }
    }
}
