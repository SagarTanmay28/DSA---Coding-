int findCircleNum(vector<vector<int>>& adj) {
    int n = adj.size();
    int count = 0;
    vector<bool> vis(n, false);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            bfs(i, vis, adj);
            count++;
        }
    }
    return count;
}

void bfs(int i, vector<bool>& vis, vector<vector<int>>& adj) {
    int n = adj.size();
    vis[i] = true;
    queue<int> q;
    q.push(i);

    while(q.size() > 0) {
        int front = q.front();
        q.pop();

        for(int j = 0; j < n; j++) {
            if(adj[front][j] == 1 && vis[j] == false) {
                q.push(j);
                vis[j] = true;
            }
        }
    }
}
