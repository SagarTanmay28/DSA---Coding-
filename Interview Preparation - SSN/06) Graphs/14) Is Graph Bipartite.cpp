class Solution {
public:
    bool ans;

    void bfs(int i, vector<vector<int>>& adj, vector<int>& visited) {
        queue<int> q;
        visited[i] = 0;
        q.push(i);

        while(q.size() > 0) {
            int front = q.front();
            q.pop();

            int color = visited[front];

            for(int ele : adj[front]) {
                if(visited[ele] == visited[front]) {
                    ans = false;
                    return;
                }
                if(visited[ele] == -1) {
                    visited[ele] = 1 - color;
                    q.push(ele);
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& adj) {
        ans = true;
        int n = adj.size();
        vector<int> visited(n, -1);

        for(int i = 0; i < n; i++) {
            if(ans == false) return ans;
            if(visited[i] == -1) bfs(i, adj, visited);
        }
        return ans;
    }
};
