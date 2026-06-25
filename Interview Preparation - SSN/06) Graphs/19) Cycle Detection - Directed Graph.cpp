// BFS 

class Solution {
  public:
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        int count = 0;
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(q.size()){
            
            int front = q.front();
            q.pop();
            
            count++;
            
            for(auto neigh : adj[front]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        
        return count < n;
    }
};


// DFS 

class Solution {
public:
    bool ans = true; // true means no cycle

    void dfs(int node, vector<vector<int>>& adj,
             vector<bool>& vis, vector<bool>& path) {

        vis[node] = true;
        path[node] = true;

        for (int neigh : adj[node]) {

            // Cycle found
            if (path[neigh]) {
                ans = false;
                return;
            }

            // Visit unvisited node
            if (!vis[neigh]) {
                dfs(neigh, adj, vis, path);
            }
        }

        path[node] = false;
    }

    bool isCyclic(int n, vector<vector<int>>& pre) {

        vector<vector<int>> adj(n);

        // b -> a edge
        for (auto &p : pre) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }

        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, path);
            }
        }

        return ans;
    }
};
