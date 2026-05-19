void bfs(int i, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[i] = true;
    queue<int> q;
    q.push(i);

    while(q.size() > 0) {
        int front = q.front();
        q.pop();

        for(auto j : adj[front]) {
            if(vis[j] == false) {
                q.push(j);
                vis[j] = true;
            }
        }
    }
}
